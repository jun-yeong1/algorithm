def solve(a: list) -> int:
  return sum(a)

n = []
n = list(map(int, input().split()))
print(solve(n))