package arrayans

import (
	"math"
)

func AllocateBooks(arr []int, m, pages int) int {
	students := 1
	noOfPages := 0
	for i := 0; i < len(arr); i++ {
		if noOfPages+arr[i] <= pages {
			noOfPages += arr[i]

		} else {
			students++
			noOfPages = arr[i]
		}
	}

	return students
}

func AllocateMinNumOfPages_Brute(arr []int, m int) int {
	n := len(arr)
	if n < m {
		return -1
	}

	low := math.MinInt64
	high := 0
	for i := 0; i < n; i++ {
		high += arr[i]
		if low < arr[i] {
			low = arr[i]
		}
	}

	for pages := low; pages <= high; pages++ {
		if AllocateBooks(arr, m, pages) == m {
			return pages
		}
	}

	return low
}

func AllocateMinNumOfPages_Optimal(arr []int, m int) int {
	n := len(arr)
	if n < m {
		return -1
	}

	low := math.MinInt64
	high := 0
	for i := 0; i < n; i++ {
		high += arr[i]
		if low < arr[i] {
			low = arr[i]
		}
	}

	for low <= high {
		mid := (low + high) / 2

		if AllocateBooks(arr, m, mid) > m {
			low = mid + 1

		} else {
			high = mid - 1
		}
	}

	return low
}
