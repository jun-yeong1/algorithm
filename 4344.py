n = int(input())
num = []
count = 0
for i in range(n):
  count = 0
  result = 0
  studentnum = list(map(int, input().split()))
  student = studentnum[0]
  num = studentnum[1:len(studentnum)]
  mnum = sum(num) / len(num)

  for i in num:
    if i > mnum:
      count += 1
  result = count / student * 100
  print(f"{result:.3f}%")
