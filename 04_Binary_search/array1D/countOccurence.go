package array1d

// Time :- O(N)
func CountOccurenceBrute(arr []int, target int) int {
	n := len(arr)
	count := 0

	for i := 0; i < n; i++ {
		if arr[i] == target {
			count++
		}
	}

	return count
}

func FirstOccurence(arr []int, target int) int {
	index := -1
	low := 0
	high := len(arr) - 1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] < target {
			low = mid + 1

		} else if arr[mid] > target {
			high = mid - 1

		} else {
			index = mid
			high = mid - 1
		}
	}

	return index
}

func LastOccurence(arr []int, target int) int {
	index := -1
	low := 0
	high := len(arr) - 1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] < target {
			low = mid + 1

		} else if arr[mid] > target {
			high = mid - 1

		} else {
			index = mid
			low = mid + 1
		}
	}

	return index
}

// Time :- O(Log N + Log N)
func CountOccurenceOptimal(arr []int, target int) int {
	first := FirstOccurence(arr, target)
	last := LastOccurence(arr, target)

	if first != -1 || last != -1 {
		return last - first + 1
	}

	return 0
}
