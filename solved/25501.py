import sys

def recursion(s, l, r):
  # 함수 호출 개수세기
    recursion.counter += 1
    if l >= r: return 1
    elif s[l] != s[r]: return 0
    else: 
      return recursion(s, l + 1, r - 1)

def isPalindrome(s):
    return recursion(s, 0, len(s)-2)

T = int(input())

recursion.counter = 0

for _ in range(T):
  s = str(sys.stdin.readline())
  print(isPalindrome(s), recursion.counter)
  s = []
  recursion.counter = 0
  
