import sys

N = int(input())

array = list(map(int, sys.stdin.readline().split()))

M = int(input())

array.sort()
start, end = 0, array[N - 1]

while(start <= end):
    mid = (start + end) // 2
    cost = 0
    for i in array:
      if i >= mid : 
        cost += mid
      else:
        cost += i
    if cost <= M:
      start = mid + 1
    else:
      end = mid - 1
print(end)