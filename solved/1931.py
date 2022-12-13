import sys

n = int(input())

array = []
result = 1
max = 0
for _ in range(n):
  array.append(list(map(int, sys.stdin.readline().split())))
  
array.sort(key=lambda x : (x[1], x[0]))
max = array[0][1]
for i in range(1, n):
  if array[i][0] == max or array[i][0] > max:
    max = array[i][1]
    result += 1

print(result)