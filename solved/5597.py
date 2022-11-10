array = [0] * 30

for i in range(28):
  n = int(input())
  array[n - 1] = n
  
for j in range(30):
  if array[j] == 0:
    print(j + 1)  
