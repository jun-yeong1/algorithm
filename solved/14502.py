from collections import deque
import copy

def wall(count):
  if count == 3:
    bfs()
    return
  for i in range(n):
    for j in range(m):
      if graph[i][j] == 0:
        graph[i][j] = 1
        wall(count + 1)
        graph[i][j] = 0
          
def bfs():
  queue = deque()
  wall_graph = copy.deepcopy(graph)
  for i in range(n):
    for j in range(m):
      if wall_graph[i][j] == 2:
        queue.append((i, j))
  while queue:
    x, y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx < 0 or nx >= n or ny < 0 or ny >= m:
        continue
      if wall_graph[nx][ny] == 0:
          wall_graph[nx][ny] = 2
          queue.append((nx, ny))
  global result
  num = 0
  for i in range(n):
    for j in range(m):
      if wall_graph[i][j] == 0:
        num += 1
  result = max(result, num)
        
# n 세로 m 가로
n, m = map(int, input().split())
graph = []
for _ in range(n):
  graph.append(list(map(int, input().split())))

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
result = 0
wall(0)
print(result)