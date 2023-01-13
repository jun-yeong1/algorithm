import sys
from collections import deque
def bfs(): # 미리 토마토 위치 저장 후 bfs
  while queue:
    x, y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx >= 0 and nx < n and ny >= 0 and ny < m and graph[nx][ny] == 0:
        graph[nx][ny] = graph[x][y] + 1
        queue.append((nx, ny))
  return graph
m, n = map(int, input().split())
queue = deque()
graph = []
for i in range(n):
  graph.append(list(map(int, sys.stdin.readline().split())))

dx = [1, -1 , 0, 0]
dy = [0, 0, -1, 1]
result = 0
for i in range(n):
  for j in range(m):
    if graph[i][j] == 1:
      queue.append((i, j))
bfs()
for i in graph:
  for j in i:
    if j == 0:
      print(-1)
      exit(0)
  result = max(result, max(i))
print(result - 1)