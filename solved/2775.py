T = int(input())

aptK = []
aptn = []
for i in range(T):
  aptK.append(int(input()))
  aptn.append(int(input()))

d = []
for apt in range(0, max(aptK) + 1):
  d.append([[apt, 0] for row in range(max(aptn))])

for j in range(1, max(aptn) + 1):
  d[0][j - 1][1] = j

for k in range(1, max(aptK) + 1):
  for h in range(0, max(aptn)):
    if h != 0:
      d[k][h][1] = d[k][h - 1][1] + d[k - 1][h][1]
    else:
      d[k][h][1] = d[k - 1][h][1]
      
for m in range(T):
  print(d[aptK[m]][aptn[m] - 1][1])