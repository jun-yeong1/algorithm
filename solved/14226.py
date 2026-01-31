from collections import deque
import sys

input = sys.stdin.readline
a = int(input())
# [위치][클립수]
S = [[-1] * (a+1) for _ in range(a+1)]
q = deque()
q.append((1, 0))
S[1][0] = 0
while q:
    # popleft 0번째, pop 마지막
    cnt, clip = q.popleft()
    if cnt == a:
        print(S[cnt][clip])
        break
    # 복사
    if (S[cnt][cnt] == -1):
        q.append((cnt, cnt))
        S[cnt][cnt] = S[cnt][clip] + 1
    # 붙여넣기
    if (clip != 0 and cnt + clip <= a and S[cnt+clip][clip] == -1):
        q.append((cnt + clip, clip))
        S[cnt+clip][clip] = S[cnt][clip] + 1
    # 하나 빼기
    if (cnt - 1 >= 0 and S[cnt-1][clip] == -1):
        q.append((cnt-1, clip))
        S[cnt-1][clip] = S[cnt][clip] + 1