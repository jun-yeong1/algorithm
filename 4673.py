def dn(n):
  if n < 10:
    dnum = n + n
  else:
    firstnum = n // 10
    secondnum = n - (firstnum * 10) 
    dnum = n + firstnum + secondnum
  return dn(dnum)
  dnum = 0

for i in range(1,100,1):
  while True:
    num = i
    if dn(i) // i == 0:
      continue
    else:
      break
    
    
  print(i) 
  