def sel_sort(a):
    n = len(a)
    b = []
    while n > 1:
        x = max(a)
        a.remove(x)
        b = [x] + b
        n = n - 1
    return b

def sel_sort_rec(a):
    if a != []:
        x = max(a)
        a.remove(x)
        return sel_sort_rec(a) + [x]
    else:
        return []

