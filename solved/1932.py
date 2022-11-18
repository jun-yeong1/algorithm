import sys

n = int(input())
dp = []

for _ in range(n):
  dp.append(list(map(int, sys.stdin.readline().split())))

for i in range(1, n):
  for j in range(0, i + 1):
    if j == 0:
      dp[i][0] += dp[i - 1][0] # 0번 째는 자신의 상위 0번째에 더함
    elif j == i:
      dp[i][j] += dp[i - 1][j - 1] # 끝도 자신의 상위 끝에 더함
    else:
      # 그 외는 상위 두 가지 숫자 중 큰 것을 받아옴
      dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]) 

print(max(dp[n - 1]))