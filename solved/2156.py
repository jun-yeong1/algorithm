n = int(input())

grape = []

for _ in range(n):
  grape.append(int(input()))

dp = [0] * n

dp[0] = grape[0]
dp[1] = grape[0] + grape[1]

for i in range(n):
  


print(max(dp))