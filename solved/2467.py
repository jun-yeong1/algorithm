import sys

input = sys.stdin.readline

n = int(input())

array = list(map(int, input().split()))

array.sort()
start, end = 0, n - 1
first = array[start] + array[end]
A, B = start, end

while (start < end):
  sum = array[start] + array[end]
  if abs(first) > abs(sum):
    first = sum
    A = start
    B = end
    if sum == 0:
      break
  if sum < 0:
    start += 1
  else:
    end -= 1
    
print(array[A], array[B])