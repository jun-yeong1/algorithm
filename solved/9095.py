n = int(input())

array = []
for i in range(n):
  array.append(int(input()))

d = [0] * 12
d[1] = 1
d[2] = 2
d[3] = 4

for j in range(4, 12):
  #점화식 각 경우의 수에 1 또는 2 또는 3을 뺀 것과 같다.
  d[j] = d[j - 1] + d[j - 2] + d[j - 3]
    
for k in range(n):
  print(d[array[k]])
  