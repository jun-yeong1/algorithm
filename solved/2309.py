import sys

array = []

for _ in range(9):
  array.append(int(sys.stdin.readline()))

array.sort()
num = sum(array)
A = num - 100

for i in range(8, -1, -1):
  A = A - array[i]
  for j in range(0, i):
    if (A - array[j]) == 0:
      del array[i]
      del array[j]
      break
  if len(array) == 7:
    break
  A = num - 100
    
print(*array, sep='\n')
