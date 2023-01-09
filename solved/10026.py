from collections import deque
import sys

def bfs(i, j, color, arr):
  queue = deque()
  queue.append((i, j))
  arr[i][j] = 0
  while queue:
      x, y = queue.popleft()
      for idx in range(4):
        nx = x + dx[idx]
        ny = y + dy[idx]
        if nx < 0 or nx >= n or ny < 0 or ny >= n:
          continue
        if arr[nx][ny] == color:
          arr[nx][ny] = 0
          queue.append((nx, ny))
            
n = int(input())
graph = []
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
for i in range(n):
  graph.append(list(sys.stdin.readline().rstrip()))

rg = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
  for j in range(n):
    if graph[i][j] == 'R' or graph[i][j] == 'G':
      rg[i][j] = 'R'
    else:
      rg[i][j] = 'B'
      
result_rgb, result_b = 0, 0
for i in range(n):
  for j in range(n):
    if graph[i][j] != 0:
      bfs(i, j, graph[i][j], graph)
      result_rgb += 1
    if rg[i][j] != 0:
      bfs(i, j, rg[i][j], rg)
      result_b += 1
      
print(result_rgb, result_b)
