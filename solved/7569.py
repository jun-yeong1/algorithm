import sys
from collections import deque

def bfs():
  while queue:
    z, x, y = queue.popleft()
    for i in range(6):
      nx = x + dx[i]
      ny = y + dy[i]
      nz = z + dz[i]
      if 0 <= nx < n and 0 <= ny < m and 0 <= nz < h and tomato[nz][nx][ny] == 0:
        tomato[nz][nx][ny] = tomato[z][x][y] + 1
        queue.append((nz, nx, ny))
m, n, h = map(int, input().split())
tomato = [[] for _ in range(h)]
for i in range(h):
  for j in range(n):
    tomato[i].append(list(map(int, sys.stdin.readline().split())))
queue = deque()
for i in range(h):
  for j in range(n):
    for k in range(m):
      if tomato[i][j][k] == 1:
        queue.append((i, j, k))
            
dx = [1, -1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]
bfs()
result = 0
for i in tomato:
  for j in i:
    for k in j:
      if k == 0:
        print(-1)
        exit(0)
    result = max(result, max(j))
print(result - 1)