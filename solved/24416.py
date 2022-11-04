n = int(input())

def fib(n):
  if n == 1 or n == 2:
    return 1
  else:
    result = 0
    itera, iterb = 0, 1
    for j in range(2, n + 1):
      result = itera + iterb
      itera = iterb
      iterb = result
  return result
def fibonacci(n):
  j = 0
  f = [0] * (n + 1)
  f[1] = 1
  f[2] = 1
  for i in range(3, n + 1):
     f[i] = f[i - 1] + f[i - 2]
     j += 1
  return j

print(fib(n), fibonacci(n))