import sys

n = int(input())

array = [0] * 10001

for i in range(n):
  array[int(sys.stdin.readline())] += 1

for j in range(10001):
  if array[j] != 0:
    for k in range(array[j]):
      print(j)