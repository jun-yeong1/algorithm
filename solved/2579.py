n = int(input())

stair = []

for _ in range(n):
  stair.append(int(input()))

dp = [0] * (n + 1)
dp[1] = stair[0]

if n > 2:
  if n == 3:
    print(max(stair[n - 1] + stair[n - 3], stair[n - 1] + stair[n - 2]))
  else:
    for i in range(2, n + 1):
      dp[i] = max(stair[i - 1] + dp[i - 2], stair[i - 1] + stair[i - 2] + dp[i - 3])
    print(dp[n])
elif n == 1:
  print(stair[n - 1])
else:
  print(stair[n - 1] + stair[n - 2])