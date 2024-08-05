package arrayans

import "math"

func FindMax(arr []int) int {
	maxi := math.MinInt64
	for i := 0; i < len(arr); i++ {
		if maxi < arr[i] {
			maxi = arr[i]
		}
	}

	return maxi
}

func ReqTime(arr []int, h int) int {
	hours := 0
	for i := 0; i < len(arr); i++ {
		hours += int(math.Ceil(float64(arr[i]) / float64(h)))
	}

	return hours
}

// Time :- O(N * max(arr[]))
func KokoBananasBrute(arr []int, h int) int {
	maxi := FindMax(arr)

	for i := 1; i <= maxi; i++ {
		reqTime := ReqTime(arr, i)
		if reqTime <= h {
			return i
		}
	}

	return maxi
}

// Time :- (N * Log (max(arr[])))
func KokoBananasOptimal(arr []int, h int) int {
	maxi := FindMax(arr)
	low := 1
	high := maxi

	for low <= high {
		mid := (low + high) / 2
		reqTime := ReqTime(arr, mid)

		if reqTime <= h {
			high = mid - 1

		} else {
			low = mid + 1
		}
	}

	return low
}
