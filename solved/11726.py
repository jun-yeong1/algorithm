n = int(input())

d = [0] * (n + 1)

d[0] = 1  # 2*1
d[1] = 2  # 2*2
# 2*1 로 시작하거나 2*2 로 시작하는 경우
for i in range(2, n + 1):
  d[i] = d[i - 1] + d[i - 2]

print(d[n - 1] % 10007)