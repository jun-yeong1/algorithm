from collections import deque

def bfs():
  while queue:
    x, y = queue.popleft()
    for i in range(8):
      nx = x + dx[i]
      ny = y + dy[i]
      if 0 <= nx < length and 0 <= ny < length:
        if chess[nx][ny] == 0:
          chess[nx][ny] = chess[x][y] + 1
          queue.append((nx, ny))
        
n = int(input()) #테스트 케이스 갯수
chess = []

dx = [2, 2, -2, -2, 1, -1, 1, -1]
dy = [1, -1, 1, -1, 2, 2, -2, -2]

for i in range(n):
  length = int(input())
  chess = [[0 for i in range(length)] for j in range(length)]
  now_x, now_y = map(int, input().split())
  t_x, t_y = map(int, input().split())
  if (now_x, now_y) == (t_x, t_y):
    print(0)
  else:
    queue = deque()
    queue.append((now_x, now_y))
    bfs()
    print(chess[t_x][t_y])
  chess = []