n = int(input())
array = list(map(int, input().split()[:n]))
max = max(array)
arrays = []
for i in array:
  arrays.append(i / max * 100)
sum = sum(arrays)
print(sum / n)

