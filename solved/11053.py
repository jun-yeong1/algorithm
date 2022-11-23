import sys

n = int(input())

num = list(map(int, sys.stdin.readline().split()))

dp = [0] * n

dp[0] = 1
# LIS 최장 증가 부분 수열 문제
for i in range(1, n): 
  val = 0 # 현재 위치를 넣을 값
  for j in range(i):
    if num[i] > num[j]: # 현재 위치보다 이전의 값이 작은지
      if val < dp[j]: # 작다면 그 위치의 값이 val보다 큰지
        val = dp[j] # 크면 j 위치 원소가 포함되었을 때가 최장 길이
  dp[i] = val + 1 # 위 조건이 아니라면 현재 위치에서 +1이 최장 길이 

print(max(dp))