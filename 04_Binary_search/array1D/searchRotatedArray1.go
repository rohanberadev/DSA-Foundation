package array1d

// Time :- O(N)
func SearchRotatedArray1Brute(arr []int, target int) int {
	n := len(arr)

	for i := 0; i < n; i++ {
		if arr[i] == target {
			return i
		}
	}

	return -1
}

// Time :- O(Log N)
func SearchRotatedArray1Optimal(arr []int, k int) int {
	low := 0
	high := len(arr) - 1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] == k {
			return mid
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

	return -1
}
