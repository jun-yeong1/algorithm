import sys

n, m = input().split()

n_array, m_array = [], []

for _ in range(int(n)):
  n_array.append(sys.stdin.readline().rstrip())

for _ in range(int(m)):
  m_array.append(sys.stdin.readline().rstrip())

result = set(n_array) & set(m_array)
result = list(result)
result.sort()
print(len(result))
for i in range(len(result)):
  print(result[i])