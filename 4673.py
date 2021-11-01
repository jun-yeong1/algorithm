def dn(n):
  n = str(n)
  dnum = 0
  for i in n:
    i = int(i)
    dnum += i
  dnum = int(n) + dnum
  return dnum

num = []
for i in range(1,10000,1):
  num.append(dn(i))
num = set(num) #정렬해야 함
for k in range(1,10000,1):
  if k in num:
    pass
  else:
    print(k) 