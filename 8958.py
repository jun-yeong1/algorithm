n = int(input())
idx = 0
result = 0
for i in range(n):
  i = str(input())
  idx = 0
  result = 0
  for j in i:
    if j == "O":
      idx += 1 
      result += idx
    else:
      idx = 0
  print(result)
