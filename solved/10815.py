import sys

input()
n = set(list(map(int, sys.stdin.readline().split())))

input()
m = list(map(int, sys.stdin.readline().split()))

for i in m:
  if i in n:
    print(1, end=' ')
  else:
    print(0, end=' ')