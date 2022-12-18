import sys
from bisect import bisect_left, bisect_right

input()
n = list(map(int, sys.stdin.readline().split()))

input()
m = list(map(int, sys.stdin.readline().split()))

n.sort()
def count(array, left_value, right_value):
  right = bisect_right(array, right_value)
  left = bisect_left(array, left_value)
  return right - left

for i in range(len(m)):
  print(count(n, m[i], m[i]), end=' ')