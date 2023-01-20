from collections import deque
import sys
sys.setrecursionlimit(10**6)

def bfs(x, y, value, visited):
  queue = deque()
  queue.append((x, y))
  visited[x][y] = 1
  while queue:
    x, y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if 0 <= nx < n and 0 <= ny < n:
        if graph[nx][ny] > value and visited[nx][ny] == 0:
          visited[nx][ny] = 1
          queue.append((nx, ny))
n = int(input())
graph = []
max = 0
for i in range(n):
  graph.append(list(map(int, sys.stdin.readline().split())))
  for j in range(n):
    if graph[i][j] > max:
      max = graph[i][j]
      
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
result = 0
for i in range(101):
  visited = [[0] * n for i in range(n)]
  cnt = 0
  for j in range(n):
    for k in range(n):
      if graph[j][k] > i and visited[j][k] == 0:
        bfs(j, k, i, visited)
        cnt += 1
  if result < cnt:
    result = cnt
print(result)