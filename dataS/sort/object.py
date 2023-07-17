from selectionSort import *
from bubbleSort import *
from insertionSort import *
from mergeSort import *
from quickSort import *
from heapSort import *
from shellSort import *
import random
import time
import sys

sys.setrecursionlimit(10000000)
listLength = 10000

B= []
for value in range(0, listLength):
    B.append(random.randint(0, 100))
#선택정렬 재귀적    
A = B
start= time.time()
selectionSort(A)
end= time.time()
print('Selection Sort (recusive) Processing Time: ', end-start)

A = B
start= time.time()
selectionSortFast(A)
end= time.time()
print('Selection Sort fast Processing Time: ', end-start)

# #버블정렬 재귀적
# A = B
# start= time.time()
# bubbleSortRec(A, listLength)
# end= time.time()
# print('Bubble Sort (recusive) Processing Time: ', end-start)

# #삽입정렬 재귀적
# A = B
# start= time.time()
# insertionSort(A, 1, len(A)-1)
# end= time.time()
# print('Insertion Sort (recusive) Processing Time: ', end-start)

# # 병합정렬
# A = B
# start= time.time()
# mergeSort(A, A[0], A[-1])
# end= time.time()
# print('mergeSort (recusive) Processing Time: ', end-start)

# # 퀵정렬
# A = B
# start= time.time()
# quickSort(A, A[0], A[-1])
# end= time.time()
# print('quickSort Processing Time: ', end-start)

# # 힙정렬
# A = B
# start= time.time()
# heapSort(A)
# end= time.time()
# print('heapSort Processing Time: ', end-start)

# # 쉘정렬
# A = B
# start= time.time()
# shellSort(A)
# end= time.time()
# print('shellSort Processing Time: ', end-start)
