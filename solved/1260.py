from collections import deque
import sys

def dfs(graph, v, visited):
  visited[v] = True
  print(v, end=' ')
  for i in graph[v]:
    if not visited[i]:
      dfs(graph, i, visited)
      
def bfs(graph, start, visited):
  queue = deque([start])
  visited[start] = True
  while queue:
    v = queue.popleft()
    print(v, end=' ')
    for i in graph[v]:
      if not visited[i]:
        queue.append(i)
        visited[i] = True

n, m, v = list(map(int, input().split()))

array = []
array.append(0)
for i in range(m):
  array.append(list(map(int, sys.stdin.readline().split())))
  
graph = [[] for _ in range(n + 1)]

for j in range(1, m + 1):
  graph[array[j][0]].append(array[j][1])
  graph[array[j][1]].append(array[j][0])

for k in range(1, n + 1):
  graph[k].sort()

visited_dfs = [False] * (n + 1)
dfs(graph, v, visited_dfs)
print(sep='\n')
visited_bfs = [False] * (n + 1)
bfs(graph, v, visited_bfs)