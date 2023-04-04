N = int(input())

def hanoi(n, a, b, c) :
    if n == 1 :
        print(a, c)
        return
    hanoi(n - 1, a, c, b) # a에 있는 n-1개를 b에 옮김
    print(a, c) # a에 남은 원반을 c로 옮기기
    hanoi(n - 1, b, a, c) # b에 있는 n-1을 c에 옮김

print(2 ** N - 1) # 2 ^ n - 1 
hanoi(N, 1, 2, 3)