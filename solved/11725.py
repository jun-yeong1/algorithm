from collections import deque
import sys

def bfs(root, v, tree):
  queue = deque([v])
  while queue:
    x = queue.popleft()
    for i in root[x]:
      if tree[i] == 0 and i != 1:
        queue.append(i)
        tree[i] = x
n = int(input())
root = [[] for _ in range(n + 1)] 
tree = [0] * (n + 1)
for i in range(n - 1):
  f, s = map(int, sys.stdin.readline().split())
  root[f].append(s)
  root[s].append(f)
bfs(root, 1, tree)
for i in range(2, n + 1):
  print(tree[i])