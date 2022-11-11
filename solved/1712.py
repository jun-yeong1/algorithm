import sys

abc = list(map(int, sys.stdin.readline().split()))



if abc[2] - abc[1] <= 0:
  print(-1)
else:
  x = abc[0] // (abc[2] - abc[1])
  print(x + 1)