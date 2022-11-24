import sys
import bisect #이분 탐색

n = int(input())

num = list(map(int, sys.stdin.readline().split()))

dp = [num[0]]

# 이분탐색 시간복잡도 O(nlogn)
for i in range(n):
  if dp[-1] < num[i]:
    dp.append(num[i])
  else:
    #bisecr.bisect_lef(arr, x) arr가 정렬되어있다는 
    # 가정하에 x값 들어갈 위치 반환
    idx = bisect.bisect_left(dp, num[i])
    dp[idx] = num[i]
print(len(dp))