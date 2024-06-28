package array1d

// Time :- O(N) Space :- O(1)
func FindPeakElementBrute(arr []int) int {
	n := len(arr)

	for i := 0; i < n-1; i++ {
		if i > 0 && i < n-1 {
			if arr[i] > arr[i-1] && arr[i] > arr[i+1] {
				return i
			}
		} else {
			if arr[i] > arr[i+1] {
				return i
			}

			if arr[n-1] > arr[n-2] {
				return i
			}
		}
	}

	return -1
}

func FindPeakElementOptimal(arr []int) int {
	n := len(arr)

	if n == 1 {
		return 0
	}
	if arr[0] > arr[1] {
		return 0
	}
	if arr[n-1] > arr[n-2] {
		return n - 1
	}

	low := 1
	high := n - 1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1] {
			return mid
		}

		if arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1] {
			low = mid + 1

		} else {
			high = mid - 1
		}
	}

	return -1
}
