import sys

n = list(map(int, sys.stdin.readline().split()))

a = n[2] - n[1]
b = n[0] - n[1]
x = a // b

if a % b == 0:
  print(x)
else:
  print(x + 1)