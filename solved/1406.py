import sys

stack_a = list(sys.stdin.readline().rstrip())
stack_b = []
num = int(input())

for _ in range(num):
    p = list(sys.stdin.readline())
    if p[0] == "L":
        if len(stack_a) != 0:
            stack_b.append(stack_a.pop())
    elif p[0] == "D":
        if len(stack_b) != 0:
            stack_a.append(stack_b.pop())
    elif p[0] == "B":
        if len(stack_a) != 0:
            stack_a.pop()
    else:
        stack_a.append(p[2])
        
stack_b = list(reversed(stack_b))
result = stack_a + stack_b

print(*result, sep="")
