package array1d

func BinarySearchIterative(arr []int, target int) int {
	n := len(arr)
	low := 0
	high := n - 1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] < target {
			low = mid + 1

		} else if arr[mid] > target {
			high = mid - 1

		} else {
			return mid
		}
	}

	return -1
}

func BinarySearchRecursive(arr []int, low, high, target int) int {
	if low <= high {
		mid := (low + high) / 2

		if arr[mid] < target {
			return BinarySearchRecursive(arr, mid+1, high, target)

		} else if arr[mid] > target {
			return BinarySearchRecursive(arr, low, mid-1, target)

		} else {
			return mid
		}
	}

	return -1
}
