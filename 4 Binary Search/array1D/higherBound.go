package array1d

// Time :- O(N)
func HigherBoundBrute(arr []int, x int) int {
	n := len(arr)

	for i := 0; i < n; i++ {
		if arr[i] > x {
			return i
		}
	}

	return -1
}

// Time :- O(Log N)
func HigherBoundOptimal(arr []int, x int) int {
	ans := -1
	n := len(arr)
	low := 0
	high := n - 1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] > x {
			high = mid - 1
			ans = mid

		} else {
			low = mid + 1
		}
	}

	return ans
}
