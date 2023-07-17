def mergeSort(A, p:int, r:int):
	if p < r:
		q = (p+r) // 2
		mergeSort(A, p, q)
		mergeSort(A, q+1, r)
		merge(A, p, q, r)

def merge(A, p:int, q:int, r:int):
	i = p; j = q+1; t = 0
	tmp = [0 for i in range(len(A))]
	while i <= q and j <= r:
		if A[i] <= A[j]:
			tmp[t] = A[i]; t += 1; i += 1
		else:
			tmp[t] = A[j]; t += 1; j += 1
	while i <= q:
		tmp[t] = A[i]; t += 1; i += 1
	while j <= r:
		tmp[t] = A[j]; t += 1; j += 1
	i = p; t = 0
	while i <= r:
		A[i] = tmp[t]; t += 1; i += 1

# 코드 9-4
def mergeSortFast(A, B, p:int, r:int):
  if p < r:
    q = (p+r) // 2
    mergeSortFast(A, B, q+1, r)
    mergeSortFast(A, B, q+1, r)
    mergeFast(A, B, p, q, r)
def mergeFast(A, B, p:int, q:int, r:int):
  i = p; j = q+1; t = 0
  while i <= q and j <=r:
    if A[i] <= A[j]:
      B[t] = A[i]; t += 1; i += 1
    else:
      B[t] = A[i]; t += 1; j += 1
  while i <= q:
    B[t] = A[i]; t += 1; i += 1
  while j <= r:
    B[t] = A[i]; t += 1; i += 1
  A = B.copy()
  
def mergeSort2(A, p:int, r:int):
	if p < r:
		q = (p+r) // 2
		mergeSort2(A, p, q)
		mergeSort2(A, q+1, r)
		merge2(A, p, q, r)

def merge2(A, p:int, q:int, r:int):
	i = p
	j = q + 1
	t = p  # 보조 리스트 tmp의 시작 인덱스를 p로 설정
	tmp = A.copy()  # A를 보조 리스트 tmp로 복사

	while i <= q and j <= r:
		if tmp[i] <= tmp[j]:
			A[t] = tmp[i]
			i += 1
		else:
			A[t] = tmp[j]
			j += 1
		t += 1

	while i <= q:
		A[t] = tmp[i]
		t += 1
		i += 1

	while j <= r:
		A[t] = tmp[j]
		t += 1
		j += 1