package medium

import "math"

// Time :- O(N^3) Space :- O(1)
func MaximumSubarraySumBrute(arr []int) int {
	n := len(arr)
	maxSum := math.MinInt64

	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			sum := 0

			for k := i; k <= j; k++ {
				sum += arr[k]
			}

			if maxSum < sum {
				maxSum = sum
			}
		}
	}

	return maxSum
}

// Time :- O(N^2) Space :- O(1)
func MaximumSubarraySumBetter(arr []int) int {
	n := len(arr)
	maxSum := math.MinInt64

	for i := 0; i < n-1; i++ {
		sum := 0
		for j := i; j < n; j++ {
			sum += arr[j]

			if maxSum < sum {
				maxSum = sum
			}
		}
	}

	return maxSum
}

// Time :- O(N) Space :- O(1)
func MaximumSubarraySumKandane(arr []int) int {
	n := len(arr)
	maxSum := math.MinInt64
	sum := 0

	for i := 0; i < n; i++ {
		sum += arr[i]

		if maxSum < sum {
			maxSum = sum
		}

		if sum < 0 {
			sum = 0
		}
	}

	return maxSum
}
