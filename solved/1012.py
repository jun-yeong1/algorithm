import sys
sys.setrecursionlimit(10**6)

def dfs(x, y):
  if x < 0 or x >= n or y < 0 or y >= m:
    return False
  if graph[x][y] == 1:
    graph[x][y] = 0
    dfs(x - 1, y)
    dfs(x, y - 1)
    dfs(x + 1, y)
    dfs(x, y + 1)
    return True
  return False

t = int(input())
for _ in range(t):
  m, n, k = list(map(int, input().split()))
  graph = [[0 for _ in range(m)] for _ in range(n)]
  for i in range(k):
    a, b = list(map(int, sys.stdin.readline().split()))
    graph[b][a] = 1
    a, b = 0, 0
  result = 0 

  for i in range(n):
    for j in range(m):
      if dfs(i, j) == True:
        result += 1
  print(result)