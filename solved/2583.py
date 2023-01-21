from collections import deque

def bfs(x, y):
  queue = deque()
  queue.append((x, y))
  cnt = 1
  while queue:
    y, x = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if 0 <= nx < n and 0 <= ny < m and graph[ny][nx] == 0:
        graph[ny][nx] = 1
        queue.append((ny, nx))
        cnt += 1
  return cnt
  
m, n, k = map(int, input().split())
graph = [[0 for _ in range(n)] for _ in range(m)]
for _ in range(k):
  l_x, l_y, r_x, r_y = map(int, input().split())
  for i in range(l_y, r_y):
    for j in range(l_x, r_x):
      graph[i][j] = 1
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
result = []
for i in range(m):
  for j in range(n):
    if graph[i][j] == 0:
      graph[i][j] = 1
      result.append(bfs(i, j))

print(len(result))
print(*sorted(result))