import sys
from collections import deque
def bfs(x, y):
  
  queue.append((x, y))
  while queue:
    x, y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx < 0 or nx >= n or ny < 0 or ny >= m:
        continue
      if graph[nx][ny] == 1 or graph[nx][ny] == -1:
        continue
      if graph[nx][ny] == 0:
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
for i in range(n):
  for j in range(m):
    if graph[i][j] == 1:
      bfs(i, j)
if all(0 not in l for l in graph):
  print(max(map(max, graph))-1)
else:
  print(-1)
