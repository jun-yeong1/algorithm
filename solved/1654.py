import sys

K, N = list(map(int, input().split()))

array = [int(sys.stdin.readline()) for _ in range(K)]

start = 0
end = max(array)

hight = 0

while(start <= end):
  num_N = 0
  mid = (start + end) // 2
  for i in array:
    if i >= mid:
      if mid != 0:
        num_N += i // mid
      else:
        num_N += i // 1
  if num_N < N:
    end = mid - 1
  else:
    hight = mid
    start = mid + 1

print(hight)