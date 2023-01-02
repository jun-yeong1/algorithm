import sys, bisect

n = int(input())

array = list(map(int, sys.stdin.readline().split()))

dp = [array[0]]

for i in range(n):
  if array[i] > dp[-1]:
    dp.append(array[i])
  else:
    index = bisect.bisect_left(dp, array[i])
    dp[index] = array[i]
    
print(len(dp))