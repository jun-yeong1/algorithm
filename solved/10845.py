import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
q = deque()

for _ in range(n):
    queue = input().split()
    if queue[0] == "push":
        q.append(queue[1])
    elif queue[0] == "pop":
        if q:
            print(q.popleft())
        else:
            print(-1)
    elif queue[0] == "size":
        print(len(q))
    elif queue[0] == "empty":
        if q:
            print(0)
        else:
            print(1)
    elif queue[0] == "front":
        if q:
            print(q[0])
        else:
            print(-1)
    elif queue[0] == "back":
        if q:
            print(q[-1])
        else:
            print(-1)