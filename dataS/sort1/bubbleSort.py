def bubbleSort(A):
	for numElements in range(len(A), 0, -1):
		for i in range(numElements-1):
			if A[i] > A[i+1]:
				A[i], A[i+1] = A[i+1], A[i]
                
def bubbleSortRec(A, n):    # A[0,..,n-1] 리스트의 버블정렬(재귀)
    for i in range(n-1):
        if A[i] > A[i+1]:
            A[i], A[i+1] = A[i+1], A[i]
    if n > 1:                   # n=2까지 재귀호출
        bubbleSortRec(A, n-1)   # 재귀호출
        
        
        
    