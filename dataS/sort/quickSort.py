def quickSort(A, p:int, r:int):
	if p < r:
		q = partition(A, p, r)	 # 분할
		quickSort(A, p, q-1)	 # 왼쪽 부분 리스트 정렬
		quickSort(A, q+1, r)	 # 오른쪽 부분 리스트 정렬

def partition(A, p:int, r:int) -> int:
	x = A[r]					# x: 기준 원소
	i = p-1					# i: 1구역의 끝 지점
	for j in range(p, r):	# j: 3구역의 시작 지점
		if A[j] < x:
			i += 1
			A[i], A[j] = A[j], A[i]  # 교환
	A[i+1], A[r] = A[r], A[i+1]	   # 기준 원소와 2구역 첫 원소 교환
	return i+1

# 코드 9-5

def quickSortP(A, p:int, r:int):
	if p < r:
		q = partition2(A, p, r)	 # 분할
		quickSortP(A, p, q-1)	 # 왼쪽 부분 리스트 정렬
		quickSortP(A, q+1, r)	 # 오른쪽 부분 리스트 정렬

def partition2(A, p:int, r:int) -> int:
  x = A[r]					# x: 기준 원소
  i = p-1					  # i: 1구역의 끝 지점
  j = r             # j : 2구역의 끝 지점
  for k in range(p, j):	# k: 3구역의 시작 지점
    if A[k] < x:    # 기준 원소보다 작으면
      i += 1
      A[i], A[k] = A[k], A[i]  # 1구역 교환
      if A[k] == x:  # 기준 원소와 같으면
        j -= 1
        A[j], A[k] = A[k], A[j] # 2구역 교환
  A[i + 1:r + 1], A[j:r + 1] = A[j:r + 1], A[i + 1:r + 1]	   # 기준 원소와 2구역 첫 원소 교환
  return i+1