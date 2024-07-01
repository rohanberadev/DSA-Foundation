package arrayans

import (
	"math"
)

func AllocateBooks_MySelf(arr []int, m, start, maxiIndex int) int {
	n := len(arr)
	extra := n - m
	pages := 0

	for i := start; i <= start+extra; i++ {
		pages += arr[i]
	}

	if !(maxiIndex >= start && maxiIndex <= extra+start) && (arr[maxiIndex] > pages) {
		return arr[maxiIndex]
	}

	return pages
}

func AllocateMinNumOfPages_MySelf(arr []int, m int) int {
	n := len(arr)

	if n < m {
		return -1
	}
	maxiIndex := -1
	maxi := math.MinInt64
	for i := 0; i < n; i++ {
		if maxi < arr[i] {
			maxi = arr[i]
			maxiIndex = i
		}
	}

	if n == m {
		return maxi
	}

	ans := math.MaxInt64
	extraBooks := n - m

	for i := 0; i < n-extraBooks; i++ {
		pages := AllocateBooks_MySelf(arr, m, i, maxiIndex)
		if pages < ans {
			ans = pages
		}
	}

	return ans
}

func AllocateBooks_Brute(arr []int, m, pages int) int {
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
		if AllocateBooks_Brute(arr, m, pages) == m {
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

		if AllocateBooks_Brute(arr, m, mid) > m {
			low = mid + 1

		} else {
			high = mid - 1
		}
	}

	return low
}
