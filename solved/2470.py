import sys

N = int(input())

array = list(map(int, sys.stdin.readline().split()))

array.sort()
start, end = 0, N - 1
water = array[start] + array[end]
A, B = start, end
while(start < end):
    sum = array[start] + array[end]
    if abs(water) > abs(sum):
      water = sum
      A = start
      B = end
      if sum == 0:
        break
    if sum < 0:
      start += 1
    else:
      end -= 1 
print(array[A], array[B])