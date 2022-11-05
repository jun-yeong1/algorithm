n = int(input())

d = [0] * (n + 1)

d[0] = 1
d[1] = 2

for i in range(2, n + 1):
  d[i] = d[i - 1] + d[i - 2]
  # 미리 나눠주니깐 메모리 초과 해결됨
  if d[i] >= 15746:
    d[i] = d[i] % 15746
  
print(d[n - 1])