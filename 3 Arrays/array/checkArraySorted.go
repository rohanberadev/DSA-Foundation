package array

import "math"

func CheckArraySorted(arr []int) bool {
	n := len(arr)

	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			if arr[i] > arr[j] {
				return false
			}
		}
	}

	return true
}

func CheckArraySortedOptimal(arr []int) bool {
	for i := 0; i < len(arr)-1; i++ {
		if arr[i] > arr[i+1] {
			return false
		}
	}

	return true
}

func CheckArraySortedTwoPointer(arr []int) bool {
	i := 0
	j := len(arr) - 1
	max := math.MinInt64
	min := math.MaxInt64

	for i < j {
		if arr[i] < arr[j] && arr[i] >= max && arr[j] <= min {
			max = arr[i]
			min = arr[j]
		} else {
			return false
		}

		i++
		j--
	}

	return true
}
