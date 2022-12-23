import sys

n, m = list(map(int, input().split()))

array = list(map(int, sys.stdin.readline().split()))

start = 0
end = max(array)

result = 0
while (start <= end):
  h = 0
  mid = (start + end) // 2
  for i in array:
    if i > mid:
      h += i - mid
  if h < m:
    end = mid - 1
  else:
    result = mid
    start = mid + 1

print(result)