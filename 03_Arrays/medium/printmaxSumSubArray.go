package medium

import (
	"fmt"
	"math"
)

// Time :- O(N^3) Space :- O(1)
func PrintMaximumSumSubArrayBrute(arr []int) {
	start := 0
	end := -1
	n := len(arr)
	maxSum := math.MinInt64

	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			sum := 0

			for k := i; k <= j; k++ {
				sum += arr[k]
			}

			if maxSum < sum {
				start = i
				end = j
				maxSum = sum
			}

		}
	}

	for start <= end {
		fmt.Printf("%v ", arr[start])
		start++
	}
	fmt.Print("\n")
}

// Time :- O(N^2) Space :- O(1)
func PrintMaximumSumSubArrayBetter(arr []int) {
	start := 0
	end := -1
	n := len(arr)
	maxSum := math.MinInt64

	for i := 0; i < n-1; i++ {
		sum := 0
		for j := i; j < n; j++ {
			sum += arr[j]
			if maxSum < sum {
				start = i
				end = j
				maxSum = sum
			}
		}

	}

	for start <= end {
		fmt.Printf("%v ", arr[start])
		start++
	}
	fmt.Print("\n")
}

func PrintMaximumSumSubArrayKandane(arr []int) {
	maxSum := 0
	sum := 0
	n := len(arr)
	ansStart := 0
	ansEnd := -1
	start := 0

	for i := 0; i < n; i++ {
		if sum == 0 {
			start = i
		}

		sum += arr[i]

		if sum > maxSum {
			ansStart = start
			ansEnd = i
			maxSum = sum
		}

		if sum < 0 {
			sum = 0
		}
	}

	for ansStart <= ansEnd {
		fmt.Printf("%v ", arr[ansStart])
		ansStart++
	}
	fmt.Print("\n")
}
