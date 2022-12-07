import sys

n = int(input())

array = [int(sys.stdin.readline()) for i in range(n)]
  
array = list(set(array))
array.sort()

print(*array, sep='\n')