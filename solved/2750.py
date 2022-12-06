n = int(input())

array = []

for _ in range(n):
  array.append(int(input()))
  
array = list(set(array))
array.sort()

for i in range(len(array)):
  print(array[i])