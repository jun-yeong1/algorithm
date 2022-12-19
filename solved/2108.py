import sys

n = int(input())

array = [int(sys.stdin.readline()) for _ in range(n)]

array.sort()

num = sum(array)

count = {}
# round 음수 적용
def roundTraditional(val):
    return round(val+10**(-len(str(val))-1))

# 최빈값
for i in array:
    try: count[i] += 1
    except: count[i] = 1

max(count,key=count.get)
max_count = [k for k,v in count.items() if max(count.values()) == v]


print(roundTraditional(num / n))

print(array[n // 2])
if len(max_count) == 1:
  print(max_count[0])
else:
  print(max_count[1])

print(max(array) - min(array))