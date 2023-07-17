from selectionSort import *
from bubbleSort import *
import random
import time
import sys

sys.setrecursionlimit(1000000)
listLength= 10000

B= []
for value in range(0, listLength):
    B.append(random.randint(0,1000))

A= B
start= time.time()
bubbleSort(A)
end= time.time()
print('Bubble Sort (non-recursive) Processing Time: ', end-start)

A= B
start= time.time()
bubbleSortRec(A, listLength)
end= time.time()
print('Bubble Sort (recusive) Processing Time: ', end-start)

A= B
start= time.time()
selectionSort(A)
end= time.time()
print('Selection Sort (non-recursive) Processing Time: ', end-start)

A= B
start= time.time()
selectionSortRec(A, listLength)
end= time.time()
print('Selection Sort (recusive) Processing Time: ', end-start)

