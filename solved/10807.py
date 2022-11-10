import sys

n = int(input())

array = list(map(int, sys.stdin.readline().split()))

v = int(input())
count = 0

for i in array:
    if i == v:
        count += 1

print(count)        