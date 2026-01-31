import sys
input = sys.stdin.readline

n, m = map(int, input().split())
friend = [[] for _ in range(n)]
visited = [False for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    friend[a].append(b)
    friend[b].append(a)

def dfs(start, count):
    if count == 5:
        print(1)
        sys.exit(0)
    visited[start] = True
    for i in friend[start]:
        if (visited[i] == False):
            dfs(i, count+1)
    visited[start] = False
for i in range(n):
    dfs(i, 1)
print(0)