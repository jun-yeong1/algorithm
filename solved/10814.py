import sys

n = int(input())
array = []

for _ in range(n):
  array.append(list(sys.stdin.readline().split()))

array.sort(key=lambda x : int(x[0]))

for i in range(n):
  print(array[i][0], array[i][1])