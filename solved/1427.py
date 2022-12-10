n = str(input())

array = [0] * 10
result = []

for i in range(len(n)):
  a = 0
  a = int(n[i])
  for j in range(10):
    if a == j:
      array[j] += 1

for k in range(9, -1, -1):
  if array[k] != 0:
    for m in range(array[k]):
      result.append(str(k))
      
print(''.join(result))