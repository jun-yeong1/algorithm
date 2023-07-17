def selectionSort(A):
	for last in range(len(A)-1, 0, -1):
		k = theLargest(A, last)	# A[0...last] 중 가장 큰 수 A[k] 찾기
		A[k], A[last] =  A[last], A[k]

def theLargest(A, last:int) -> int:	# A[0...last]에서 가장 큰 수의 인덱스를 리턴한다
	largest = 0
	for i in range(last+1):        # A[0,...last+1] 까지의 최대값 찾기
		if A[i] > A[largest]:
			largest = i
	return largest

# 코드 9-1

def selectionSortRec(A, n):         # 길이 n을 가지는 A[0,1,..n-1] 리스트의 선택정렬(재귀)
    if (n>2):
        k= theLargest4Rec(A, n-1)   # 0에서 n-1까지에서의 최대값 찾기
        A[k], A[n-1] = A[n-1], A[k] # 최대값 원소 A[k]와 마지막 원소 A[n-1] 교환
        selectionSortRec(A, n-1)    # 원소의 길이가 하나 줄어든 자신의 재귀호출

        
def theLargest4Rec(A, last:int) -> int:	# A[0...last]에서 가장 큰 수의 인덱스를 리턴한다
	largest = 0
	for i in range(last):          # A[0,..last] 까지의 최대값 찾기
		if A[i] > A[largest]:
			largest = i
	return largest

        
