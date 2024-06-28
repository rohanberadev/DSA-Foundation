package array

func LinearSearch(arr []int, target int) int {
	n := len(arr)

	for i := 0; i < n; i++ {
		if arr[i] == target {
			return i
		}
	}

	return -1
}
