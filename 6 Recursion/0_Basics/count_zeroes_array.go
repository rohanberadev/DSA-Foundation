package basics

func CountZeroesArray_1(arr []int, n int) int {
	count := 0
	if n == 0 {
		return 0
	}

	if arr[n-1] == 0 {
		count += 1
	}

	count += CountZeroesArray_1(arr, n-1)

	return count
}

func CountZeroesArray_2(arr []int) int {
	count := 0
	n := len(arr)

	if n == 0 {
		return 0
	}

	if arr[n-1] == 0 {
		count += 1
	}

	count += CountZeroesArray_2(arr[0 : n-1])

	return count
}
