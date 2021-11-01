array = []
for i in range(1,10,1):
  array.append(int(input()))
max = max(array)
print(max)
print(array.index(max)+1)