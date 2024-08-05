package arrayans

func FindKthMissingNum_Brute(arr []int, k int) int {
	n := len(arr)

	for i := 0; i < n; i++ {
		if arr[i] <= k {
			k++
		} else {
			return k
		}
	}

	return k
}

/*
more = k - (arr[high] - (high + 1))
ans = arr[high] + more
ans = arr[high] + k - (arr[high] - high - 1)
ans = arr[high] + k - arr[high] + high + 1
ans = high + 1 + k

low = high + 1
because low will always lie after high

therefore, ans = low + k
*/
func FindKthMissingNum_Optimal(arr []int, k int) int {
	low := 0
	high := len(arr) - 1

	for low <= high {
		mid := (low + high) / 2
		missing := arr[mid] - (mid + 1)

		if missing < k {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}

	return low + k
}
