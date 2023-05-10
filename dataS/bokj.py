def m(n, a, b, c):
  global p
  if (n > 0):
    p += 1
    m(n-1, a, c, b)
    m(n-1,c, b, a)
global p
p = 0
a, b, c = "", "", ""
m(5, a, b, c)
print(p)