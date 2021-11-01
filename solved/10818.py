n = int(input())
array = [0 for i in range(n)]
array = list(map(int, input().split()[:n]))
print(min(array), max(array))