package arrayans

import "math"

/*
Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.
A subarray is a contiguous part of the array.
*/

func CountPartitions(arr []int, maxSum int) int {
	sumSubArray := 0
	partitions := 1
	for i := 0; i < len(arr); i++ {
		if sumSubArray+arr[i] <= maxSum {
			sumSubArray += arr[i]

		} else {
			partitions++
			sumSubArray = arr[i]
		}
	}

	return partitions
}

func SplitArrayLargestSum_Brute(arr []int, k int) int {
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

	for maxSum := low; maxSum <= high; maxSum++ {
		if CountPartitions(arr, maxSum) == k {
			return maxSum
		}
	}

	return high
}

func SplitArrayLargestSum_Optimal(arr []int, k int) int {
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
		partitions := CountPartitions(arr, mid)

		if partitions <= k {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}

	return low
}
