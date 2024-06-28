package array1d

import "math"

// Time :- O(N)
func FindMinRotatedArrayBrute(arr []int) int {
	n := len(arr)
	min := math.MaxInt64

	for i := 0; i < n; i++ {
		if min > arr[i] {
			min = arr[i]
		}
	}

	return min
}

func FindMinRotatedArrayOptimal(arr []int) int {
	low := 0
	high := len(arr) - 1
	min := math.MaxInt64

	for low <= high {
		mid := (low + high) / 2

		// Both left and right halves are sorted.
		if arr[low] <= arr[high] {
			if min > arr[low] {
				min = arr[low]
			}
			break
		}

		if arr[low] <= arr[mid] {
			if min > arr[low] {
				min = arr[low]
			}
			low = mid + 1

		} else {
			if min > arr[mid] {
				min = arr[mid]
			}
			high = mid - 1
		}
	}

	return min
}
