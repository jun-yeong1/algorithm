n = int(input())

num1 = 1
num2 = 6
result = 1

while True:
  if n == 1:
    print(1)
    break
  elif n <= num1:
    print(result)
    break
  else:
    num1 += num2
    num2 += 6
    result += 1