ab = []

ab.append(input().split())

ab[0][0] = ab[0][0][::-1]
ab[0][1] = ab[0][1][::-1]

ab[0][0] = int(ab[0][0])
ab[0][1] = int(ab[0][1])

if ab[0][0] > ab[0][1]:
  print(ab[0][0])
else:
  print(ab[0][1])
