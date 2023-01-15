from collections import deque

n, k = map(int, input().split())
if n >= k:
  print(n - k)
else:
  graph = [0]* 2 * k
  for i in range(2 * k):
    graph[i] = abs(n - i)
  queue = deque()
  queue.append(n)
  while queue:
    x = queue.popleft()
    try :
      if graph[2 * x] >= graph[x] + 1:
        queue.append(2 * x)
        graph[2 * x] = graph[x] + 1
    except:
      pass
    if x > 0:
      if graph[x - 1] >= graph[x] + 1:
        queue.append(x - 1)
        graph[x - 1] = graph[x] + 1
    try :
      if graph[x + 1] >= graph[x] + 1:
        queue.append(x + 1)
        graph[x + 1] = graph[x] + 1
    except:
      pass
  print(graph[k])