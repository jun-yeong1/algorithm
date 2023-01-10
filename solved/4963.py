import sys
sys.setrecursionlimit(10**6)

def dfs(x, y):
  dx = [-1, 1, 0, 0, 1, 1, -1, -1]
  dy = [0, 0, -1, 1, 1, -1, 1, -1]
  graph[x][y] = 0
  for i in range(8):
    nx = x + dx[i]
    ny = y + dy[i]
    if 0 <= nx and nx < h and 0 <= ny and ny < w and graph[nx][ny] == 1:
      dfs(nx, ny)

while True:
  w, h = list(map(int, input().split()))
  if w == 0 and h == 0:
    break
  graph = []
  count = 0
  for i in range(h):
    graph.append(list(map(int, sys.stdin.readline().split())))
  for i in range(h):
    for j in range(w):
      if graph[i][j] == 1:
        dfs(i, j)
        count += 1
  print(count)
