import sys

n = int(input())

xi_array = list(map(int, sys.stdin.readline().split()))

xj_array = list(set(xi_array))
xj_array.sort()

xi_dict = {}
for i in range(len(xj_array)):
  xi_dict[xj_array[i]] = i

for j in xi_array:
  print(xi_dict[j], end=' ')