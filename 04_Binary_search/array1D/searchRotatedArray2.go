package array1d

// Time :- O(N)
func SearchRotatedArray2Brute(arr []int, k int) bool {
	n := len(arr)

	for i := 0; i < n; i++ {
		if arr[i] == k {
			return true
		}
	}

	return false
}

// Time :- O(Log N)
func SearchRotatedArray2Optimal(arr []int, k int) bool {
	low := 0
	high := len(arr) - 1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] == k {
			return true
		}

		if arr[low] == arr[mid] && arr[mid] == arr[high] {
			low++
			high--
			continue
		}

		if arr[low] <= arr[mid] {
			if arr[mid] > k && arr[low] <= k {
				high = mid - 1

			} else {
				low = mid + 1
			}

		} else {
			if arr[mid] < k && arr[high] >= k {
				low = mid + 1

			} else {
				high = mid - 1
			}
		}
	}

	return false
}
