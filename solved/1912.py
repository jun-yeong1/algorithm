import sys

T = int(sys.stdin.readline())

n = list(map(int, sys.stdin.readline().split()))

d = [0] * T

d[0] = n[0]

for i in range(1, T):
  d[i] = max(n[i], d[i - 1] + n[i])
  
print(max(d))