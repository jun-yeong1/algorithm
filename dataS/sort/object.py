from selectionSort import *
from bubbleSort import *
from sort.insertionSort import *
from sort.mergeSort import *
from sort.quickSort import *
from sort.heapSort import *
from sort.shellSort import *
import random
import time
import sys

sys.setrecursionlimit(1000000)
listLength = 300

B= []
for value in range(0, listLength):
    B.append(random.randint(0, 100))
#선택정렬 재귀적    
A = B
start= time.time()
selectionSortRec(A, listLength)
end= time.time()
print('Selection Sort (recusive) Processing Time: ', end-start)

#버블정렬 재귀적
A = B
start= time.time()
bubbleSortRec(A, listLength)
end= time.time()
print('Bubble Sort (recusive) Processing Time: ', end-start)

#삽입정렬 재귀적
A = B
start= time.time()
insertionSortRec(A, listLength)
end= time.time()
print('Insertion Sort (recusive) Processing Time: ', end-start)

# 병합정렬
A = B
start= time.time()
mergeSort(A, listLength)
end= time.time()
print('mergeSort (recusive) Processing Time: ', end-start)

# 퀵정렬
A = B
start= time.time()
quickSort(A, listLength)
end= time.time()
print('quickSort (recusive) Processing Time: ', end-start)

# 힙정렬
A = B
start= time.time()
heapSort(A, listLength)
end= time.time()
print('heapSort (recusive) Processing Time: ', end-start)

# 쉘정렬
A = B
start= time.time()
shellSort(A, listLength)
end= time.time()
print('shellSort (recusive) Processing Time: ', end-start)
