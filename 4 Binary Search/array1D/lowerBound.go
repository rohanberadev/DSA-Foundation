package array1d

// Time :- O(N)
func LowerBoundBrute(arr []int, x int) int {
	n := len(arr)

	for i := 0; i < n; i++ {
		if arr[i] >= x {
			return i
		}
	}

	return -1
}

// Time :- O(Log N)
func LowerBoundOptimal(arr []int, x int) int {
	n := len(arr)
	ans := n
	low := 0
	high := n - 1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] >= x {
			ans = mid
			high = mid - 1

		} else {
			low = mid + 1
		}
	}

	return ans
}
