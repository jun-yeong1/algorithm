array = []
for i in range(10):
  a = int(input())
  result = a % 42
  array.append(result)
array_r = list(set(array))
print(len(array_r))