import sys

array = []

n = int(input())

for _ in range(n):
  array.append(list(map(int, sys.stdin.readline().split())))
  
array.sort(key=lambda x : (x[1], x[0]))

for i in range(n):
  print(array[i][0], array[i][1])