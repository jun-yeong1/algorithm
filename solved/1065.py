def Xnum(n):
  if n >= 1 and n < 100:
    return True 
  elif n >= 100 and n <= 1000:
    onenum = n // 100
    twonum = (n - (onenum * 100)) // 10
    threenum = n - (onenum * 100) - (twonum * 10)
    if twonum - onenum == threenum - twonum:
      return True

N = int(input())
count = 0
for i in range(1, N+1):
  if Xnum(i) == True:
    count += 1
print(count) # 해결

