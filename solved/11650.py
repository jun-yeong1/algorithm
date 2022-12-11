import sys

n = int(input())

array = []

for _ in range(n):
  array.append(list(map(int, sys.stdin.readline().split())))

array.sort(key=lambda x : (x[0], x[1]))

for i in range(n):
  print(array[i][0], array[i][1])