X, Y = list(map(int, input().split()))

start = 0
Z = (Y * 100) // X

if Z >= 99:
  print(-1)
else:
  result = 0
  start = 1
  end = X
  while (start <= end):
    mid = (start + end) // 2
    if (Y + mid) * 100 // (X + mid) <= Z:
      start = mid + 1
    else:
      result = mid
      end = mid - 1
  print(result)