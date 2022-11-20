n = int(input())

dp = [[0] * 2 for _ in range(10)]

for i in range(1, n):
  if i > 0 and i < 9:
    dp[i][0] = i - 1
    dp[i][1] = i + 1
  
