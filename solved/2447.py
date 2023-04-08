import sys
sys.setrecursionlimit(10**6)

def star(num):
    if num == 1:
        return ['*']

    Stars = star(num // 3) 
    array = []  
    
    for i in Stars:
        array.append(i * 3)
    for i in Stars:
        array.append(i + ' ' * (num // 3) + i)
    for i in Stars:
        array.append(i * 3)
    return array

n = int(input())
print('\n'.join(star(n)))