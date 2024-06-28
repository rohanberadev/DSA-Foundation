package array1d

// Time :- O(N)
func LastOcurrenceBrute(arr []int, target int) int {
	n := len(arr)

	for i := n - 1; i >= 0; i-- {
		if arr[i] == target {
			return i
		}
	}

	return -1
}

// Time :- O(Log N)
func LastOcurrenceOptimal(arr []int, target int) int {
	low := 0
	high := len(arr) - 1
	index := -1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] < target {
			low = mid + 1

		} else if arr[mid] > target {
			high = mid - 1

		} else {
			low = mid + 1
			index = mid
		}
	}

	return index
}
