package arrayans

import "math"

/*
Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.
*/

func CountPainter(arr []int, maxPaint int) int {
	paintSum := 0
	painters := 1

	for i := 0; i < len(arr); i++ {
		if paintSum+arr[i] <= maxPaint {
			paintSum += arr[i]
		} else {
			paintSum = arr[i]
			painters++
		}
	}

	return painters
}

func PainterPartition_Brute(arr []int, k int) int {
	n := len(arr)
	if n < k {
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

	if n == k {
		return low
	}

	for paints := low; paints <= high; paints++ {
		if CountPainter(arr, paints) == k {
			return paints
		}
	}

	return high
}

func PainterPartition_Optimal(arr []int, k int) int {
	n := len(arr)
	if n < k {
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

	if n == k {
		return low
	}

	for low <= high {
		mid := (low + high) / 2
		painters := CountPainter(arr, mid)

		if painters <= k {
			high = mid - 1

		} else {
			low = mid + 1
		}
	}

	return low
}
