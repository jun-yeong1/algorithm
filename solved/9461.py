import sys

T = int(sys.stdin.readline())

n = []
for _ in range(T):
  n.append(int(sys.stdin.readline()))
  
d = [0] * (max(n) + 1)
d[0] = 1
d[1] = 1
d[2] = 1
d[3] = 2
d[4] = 2

if max(n) > 4:
  for i in range(5, max(n) + 1):
    if d[i] == 0:
      d[i] = d[i - 1] + d[i - 5]

for m in range(T):
  print(d[n[m] - 1])