n = int(input())
array_A = list(map(int, raw_input().split()))
array_B = list(map(int, raw_input().split()))
array_A.sort()
array_A.reverse()
array_B.sort()
result = 0
for i in range(n):
  result += array_A[i] * array_B[i]

print(result)