n = int(input())
array = [500, 100, 50, 10, 5, 1]
count = 0
num = 1000 - n
for coins in array:
  count += num // int(coins)
  num %= int(coins)  
print(count)