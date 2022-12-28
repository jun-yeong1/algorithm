n = int(input())
k = int(input())

array = []

for i in range(n):
  for j in range(n):
    array.append((i + 1) * (j + 1))
    
array.sort()

print(array[k])
##내일 다시 풀자