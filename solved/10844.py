import copy

n = int(input())

dp = [0] * 10
dpnum = [0] * 10

for s in range(1, 10):
  dp[s] = 1
  dpnum[s] = 1
  
for k in range(n - 1):
  for i in range(0, 10):
    if i == 0:
      dp[i] = dpnum[i + 1]
    elif i == 9:
      dp[i] = dpnum[i - 1] 
    else:
      dp[i] = dpnum[i - 1] + dpnum[i + 1]
  dpnum = copy.deepcopy(dp)
  
result = 0
if n == 1:
  print(9)
else:
  for j in range(1, 9):
    result += dp[j]
  result += dp[0] + dp[9]
  print(result % 1000000000)