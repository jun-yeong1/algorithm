n = int(input())
num = n
count = 0
result = 0

while num != result:
  if n >= 0 and n <10:
    a = 0
    b = n
    result = (b * 10) + (a + b)
    count += 1
  elif n >= 10 and n <= 99:
    a = n // 10
    b = n - (a * 10)
    if (a + b) > 10:
      seca = (a + b) // 10 
      secb = (a + b) - (seca * 10)
      result = (b * 10) + secb
      count += 1
    else:
      result = (b * 10) + (a + b)
      count += 1
  else:
    break
  n = result
print(count)