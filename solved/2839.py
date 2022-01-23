n = int(input())
array = list(map(int, input().split()))
array.sort()
for i in range(5):
  print(array[i])
print(type(array[1]))