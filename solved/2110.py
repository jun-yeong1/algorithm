import sys

N, C = map(int, input().split())

array = [int(sys.stdin.readline()) for _ in range(N)]

array.sort()
start = 1
end = array[N - 1] - array[0]
result = 0

if C == 2:
  print(end)
else:
  while(start < end):
    mid = (start + end) // 2
    count = 1 ## 공유기 갯수
    wifi_index = array[0] ## wifi_index 마지막 설치한 위치
    for i in range(N):
      if (array[i] - wifi_index) >= mid:
        count += 1
        wifi_index = array[i]
    if count >= C:
      result = mid
      start = mid + 1
    elif count < C:
      end = mid
  print(result)  