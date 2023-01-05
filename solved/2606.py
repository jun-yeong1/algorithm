import sys

n = int(input())

link = int(input())

array = []
array.append(0)
for i in range(link):
  array.append(list(map(int, sys.stdin.readline().split())))
  
graph = [[] for _ in range(n + 1)]

for j in range(1, link + 1):
  graph[array[j][0]].append(array[j][1])
  graph[array[j][1]].append(array[j][0])
  
def dfs(graph, v, visited):
  visited[v] = True
  for i in graph[v]:
    if not visited[i]:
      dfs(graph, i, visited)
      
visited = [False] * (n + 1)
dfs(graph, 1, visited)

print(visited.count(True) - 1)