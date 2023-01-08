import sys
sys.setrecursionlimit(10**6)

def dfs(v):
  visited[v] = True
  for i in graph[v]:
    if not visited[i]:
      dfs(i)
  
n, m = list(map(int, input().split()))
graph = [[] for _ in range(n + 1)]

for i in range(m):
  a, b = list(map(int, sys.stdin.readline().split()))
  graph[a].append(b)
  graph[b].append(a)

visited = [False] * (n + 1)
dfs(1)
result = 1
for i in range(1, n + 1):
  if visited[i] == False:
    dfs(i)
    result += 1
print(result)