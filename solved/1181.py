import sys

n = int(input())

array = [sys.stdin.readline().rstrip() for i in range(n)]

array = list(set(array))

array.sort(key = lambda x : (len(x), x))

print(*array, sep='\n')