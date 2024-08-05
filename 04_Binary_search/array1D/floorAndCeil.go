package array1d

func FindFloor(arr []int, k int) int {
	n := len(arr)
	floor := 0

	low := 0
	high := n - 1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] <= k {
			low = mid + 1
			floor = arr[mid]

		} else {
			high = mid - 1
		}
	}

	return floor
}

func FindCeil(arr []int, k int) int {
	n := len(arr)
	ceil := 0

	low := 0
	high := n - 1

	for low <= high {
		mid := (low + high)

		if arr[mid] >= k {
			high = mid - 1
			ceil = arr[mid]

		} else {
			low = mid + 1
		}
	}

	return ceil
}
