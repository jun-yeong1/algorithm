from collections import deque

def bfs():
  while queue:
    n = queue.popleft()
    for _ in range(3):
      if n == 
      graph[n - 1][0] = graph[n][0] + 1
      graph[n + 1][0] = graph[n][0] + 1



n, k = map(int, input().split())
graph = [[0]for _ in range(10)]
queue = deque()
queue.append(n)
bfs()