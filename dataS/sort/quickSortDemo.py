from quickSort import *
import random
import time
import sys
sys.setrecursionlimit(1000000)
listLenght = 3000
def main():
    B = []
    for value in range(0, listLenght):
      B.append(random.randint(1, 5))
    A = B
    start = time.time()
    quickSort(A, 0, len(A)-1)
    end = time.time()
    print(end-start)
    
    A = B
    start = time.time()
    quickSortP(A, 0, len(A)-1)
    end = time.time()
    print(end-start)

if __name__ == "__main__":
    main()
