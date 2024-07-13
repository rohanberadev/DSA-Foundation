package basics

func FindLastIndexOfElemArray_1(arr []int, n, key int) int {
	if n == 0 {
		return -1
	}

	if arr[n-1] == key {
		return n - 1
	}

	return FindLastIndexOfElemArray_1(arr, n-1, key)
}

func FindLastIndexOfElemArray_2(arr []int, key int) int {
	n := len(arr)

	if n == 0 {
		return -1

	} else if arr[n-1] == key {
		return n - 1
	}

	return FindLastIndexOfElemArray_2(arr[0:n-1], key)
}
