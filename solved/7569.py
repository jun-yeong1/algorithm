import sys
from collections import deque

def bfs():
  while queue:
    x, y = queue.popleft()
    for i in range(6):
      nx = x + dx[i]
      ny = y + dy[i]
      if 0 <= i < 4:
        if 0 <= x < n and 0 <= y < m:
          if 0 <= nx < n and 0 <= ny < m and tomato[nx][ny] == 0:
            tomato[nx][ny] = tomato[x][y] + 1
            queue.append((nx, ny))
        if n <= x < (n * h) and 0 <= y < m:
          if n <= nx < (n * h) and 0 <= ny < m and tomato[nx][ny] == 0:
            tomato[nx][ny] = tomato[x][y] + 1
            queue.append((nx, ny))
      else:
        if 0 <= nx < (n * h) and 0 <= ny < m and tomato[nx][ny] == 0:
          tomato[nx][ny] = tomato[x][y] + 1
          queue.append((nx, ny))
  return tomato 
 
m, n, h = map(int, input().split())
tomato = []
for _ in range(n * h):
  tomato.append(list(map(int, sys.stdin.readline().split())))
queue = deque()
for i in range(n * h):
  for j in range(m):
    if tomato[i][j] == 1:
      queue.append((i, j))     
dx = [1, -1, 0, 0, n, -n]
dy = [0, 0, 1, -1, 0, 0]
bfs()
result = 0
for i in tomato:
  for j in i:
    if j == 0:
      print(-1)
      exit(0)
  result = max(result, max(i))
print(result - 1)