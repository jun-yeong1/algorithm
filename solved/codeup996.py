array = [[0 for i in range(10)]for j in range(10)]
'''for i in range(10):
  array[i] = list(map(int, raw_input().split()))'''
for i in range(10):
  a = int(raw_input().split())
  for j in range(10):
    array[i][j] = a[j]
print(array)
x, y = 1, 1
x = int(x)
y = int(y)
while True:
  if array[x][y + 1] == 0:
    array[x][y] = 9
    y += 1
  elif array[x][y + 1] == 1:
    array[x][y] = 9
    if array[x + 1][y] == 1:
      break
    elif array[x + 1][y] == 2:
      array[x + 1][y] = 9
      break
    else:
      x += 1
  else:
    array[x][y] = 9
    array[x][y + 1] =9
    break
for i in range(10):
  for j in range(10):
    print(array[i][j]),
  print("")
