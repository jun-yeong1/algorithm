def insertionSort(A):
	for i in range(1, len(A)):
		loc = i-1
		newItem = A[i]
		while loc >= 0 and newItem < A[loc]:
			A[loc+1] = A[loc]
			loc -= 1
		A[loc+1] = newItem


# 개선 코드
def insertSort(A):
  for i in range(1, len(A)):
    for j in range(i, 0, -1):
      if A[j] < A[j - 1]:
        A[j], A[j - 1] = A[j - 1], A[j]
      else:
        break
# 코드 9-3

def insertionSortRec(A, start, end):
  value = A[start]
  loc = start
  while loc > 0 and A[loc-1] > value:
    A[loc] = A[loc-1]
    loc -= 1
  A[loc] = value
  if start + 1 < end:
    insertionSortRec(A, start+1, end)
    
def insertion_sort_recursion(arr):
    if len(arr) <= 1:
        return arr
    else:
        sorted_arr = insertion_sort_recursion(arr[:-1])
        insert_idx = len(sorted_arr)
        for i in range(len(sorted_arr)):
            if arr[-1] < sorted_arr[i]:
                insert_idx = i
                break
        return sorted_arr[:insert_idx] + [arr[-1]] + sorted_arr[insert_idx:]