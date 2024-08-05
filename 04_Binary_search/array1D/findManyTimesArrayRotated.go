package array1d

import "math"

// Time :- O(N)
func FindManyTimesArrayRotatedBrute(arr []int) int {
	n := len(arr)
	mini := math.MaxInt64
	ans := 0

	for i := 0; i < n; i++ {
		if arr[i] < mini {
			mini = arr[i]
			ans = i
		}
	}

	return ans
}

// Time :- O(Log N)
func FindManyTimesArrayRotatedOptimal(arr []int) int {
	mini := math.MaxInt64
	ans := 0
	low := 0
	high := len(arr) - 1

	for low <= high {
		mid := (low + high) / 2

		if arr[low] <= arr[high] {
			if arr[low] < mini {
				mini = arr[low]
				ans = low
			}
			break
		}

		if arr[low] <= arr[mid] {
			if arr[low] < mini {
				mini = arr[low]
				ans = low
			}
			low = mid + 1

		} else {
			if arr[high] < mini {
				mini = arr[high]
				ans = high
			}
			high = mid - 1
		}
	}

	return ans
}
