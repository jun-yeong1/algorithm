#테스트 케이스의 개수
T = int(input())

#케이스 n은 0<=n<=40
narray = [] * T
for i in range(T):
  n = int(input())
  narray.append(n)
# 대입연산자 이용시 반복문으로 사용하는 것을 권장
d = [[0 for col in range(2)] for row in range(41)]

d[0][0] = 1
d[1][1] = 1

for j in range(2, 41):
  d[j][0] = d[j - 1][0] + d[j - 2][0]
  d[j][1] = d[j - 1][1] + d[j - 2][1]

for k in range(T):
  print(d[narray[k]][0], d[narray[k]][1])
  

