import sys

n = int(input())

array = []
for _ in range(n):
  array.append(int(sys.stdin.readline()))

array.sort()

for i in range(n):
  array[i] *= n - i
  
print(max(array))