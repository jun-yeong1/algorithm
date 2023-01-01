import sys, bisect

input = sys.stdin.readline

n = int(input())

array = list(map(int, input().split()))
dp = [array[0]]

for i in range(n):
  if array[i] > dp[-1]:
    dp.append(array[i])
  else:
    index = bisect.bisect_left(dp, array[i])
    dp[index] = array[i]
    
print(len(dp))