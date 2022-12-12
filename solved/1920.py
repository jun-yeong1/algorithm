import sys
# from bisect import bisect_left, bisect_right

def binary_search(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        # 원하는 값 찾은 경우 인덱스 반환
        if array[mid] == target:
            return 1
        # 원하는 값이 중간점의 값보다 작은 경우 왼쪽 부분(절반의 왼쪽 부분) 확인
        elif array[mid] > target:
            end = mid - 1
        # 원하는 값이 중간점의 값보다 큰 경우 오른쪽 부분(절반의 오른쪽 부분) 확인
        else:
            start = mid + 1
    return 0
n = int(input())

Array_N = list(map(int, sys.stdin.readline().split()))
Array_N.sort()

m = int(input())

Array_M = list(map(int, sys.stdin.readline().split()))

for i in range(m):
  print(binary_search(Array_N, Array_M[i], 0, n - 1)) 