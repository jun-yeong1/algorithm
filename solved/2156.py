import sys

n = int(input())

grape = []

for _ in range(n):
  grape.append(int(sys.stdin.readline()))

dp = [0] * n
if n == 1:
  print(grape[0])
elif n == 2:
  print(grape[0] + grape[1])
elif n == 3:
  print(sum(grape[:3]) - min(grape[:3]))
else:
  dp[0] = grape[0]
  dp[1] = grape[0] + grape[1]
  dp[2] = dp[1] + grape[2] - min(grape[:3])

  for i in range(3, n):
    dp[i] = max(dp[i - 1], dp[i - 2] + grape[i], dp[i - 3] + grape[i - 1] + grape[i])

  print(dp[n - 1])