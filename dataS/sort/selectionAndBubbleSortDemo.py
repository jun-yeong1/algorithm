from selectionSort import *
from bubbleSort import *

def main():
    
    A = [35, 24, 16, 21, 4, 72, 23, 9, 23, 14, 58, 12, 0]
    print("A[]:	   ", A)
    # bubbleSort(A)
    selectionSort(A)
    print("(Non-Recursive) Selection Sorted A[]:", A)
    
    A = [35, 24, 16, 21, 4, 72, 23, 9, 23, 14, 58, 12, 0]
    print("A[]:	   ", A)
    # bubbleSort(A)
    selectionSortRec(A, len(A))
    print("(Recursive) Selection Sorted A[]:", A)
    
    A = [35, 24, 16, 21, 4, 72, 23, 9, 23, 14, 58, 12, 0]
    print("A[]:	   ", A)
    # bubbleSort(A)
    bubbleSort(A)
    print("(Non-Recursive) Bubble Sorted A[]:", A)
    
    A = [35, 24, 16, 21, 4, 72, 23, 9, 23, 14, 58, 12, 0]
    print("A[]:	   ", A)
    # bubbleSort(A)
    bubbleSortRec(A, len(A))
    print("(Recursive) Bubble Sorted A[]:", A)

if __name__ == "__main__":
    main()