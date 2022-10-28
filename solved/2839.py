n = int(input()) #설탕 키로수
array = [3, 5]  
#최대 5000이니깐 5001
d = [5001] * (n + 1) 

#다이나믹 프로그래밍
d[0] = 0
for i in range(2):
  for j in range(array[i], n + 1):
    if d[j - array[i]] != 5001:
      d[j] = min(d[j], d[j -array[i]] + 1)
if d[n] == 5001:
  print(-1)
else:
  print(d[n])