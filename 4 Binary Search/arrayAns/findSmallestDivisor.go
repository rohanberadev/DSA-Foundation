package arrayans

import "math"

// Time :- O(N * max(arr[]))
func FindSmallestDivisorBrute(arr []int, limit int) int {
	n := len(arr)
	maxi := FindMax(arr)
	ans := maxi

	for i := 1; i <= maxi; i++ {
		sum := 0
		for j := 0; j < n; j++ {
			sum += int(math.Ceil(float64(arr[j]) / float64(i)))
		}

		if sum <= limit {
			if ans > i {
				ans = i
			}
		}
	}

	return ans
}

func CheckPossible(arr []int, n int) int {
	sum := 0
	for i := 0; i < len(arr); i++ {
		sum += int(math.Ceil(float64(arr[i]) / float64(n)))
	}

	return sum
}

func FindSmallestDivisorOptimal(arr []int, limit int) int {
	low := 1
	high := FindMax(arr)

	for low <= high {
		mid := (low + high) / 2

		sum := CheckPossible(arr, mid)

		if sum <= limit {
			high = mid - 1

		} else {
			low = mid + 1
		}
	}

	return low
}
