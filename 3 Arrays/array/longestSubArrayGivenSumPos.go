package array

import (
	"math"
)

// Time :- O(N^3) Space :- O(1)
func FindLongestSubArrayGivenNumBrute(arr []int, sum int) int {
	n := len(arr)
	maxLen := 0

	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			currSum := 0

			for K := i; K <= j; K++ {
				currSum += arr[K]
			}

			if currSum == sum {
				maxLen = int(math.Max(float64(maxLen), float64(j-i+1)))
			}

		}
	}

	return maxLen

}

// Time :- O(N^2) Space :- O(1)
func FindLongestSubArrayGivenNumBetter(arr []int, k int) int {
	n := len(arr)
	maxLen := 0

	for i := 0; i < n-1; i++ {
		sum := 0
		for j := i; j < n; j++ {
			sum += arr[j]
			if sum == k {
				maxLen = int(math.Max(float64(maxLen), float64(j-i+1)))
			}
		}
	}

	return maxLen
}

// Time :- O(N) Space :- O(N)
func FindLongestSubArrayGivenNumHashing(arr []int, sum int) int {
	maxLen := 0
	n := len(arr)
	N := math.MaxInt64
	prefixMap := make(map[int]int, N)
	prefixSum := 0

	for i := 0; i < n; i++ {
		prefixSum += arr[i]

		if sum == prefixSum {
			maxLen = int(math.Max(float64(maxLen), float64(i+1)))
		}

		rem := prefixSum - sum

		if val, ok := prefixMap[rem]; ok {
			maxLen = int(math.Max(float64(i-val), float64(maxLen)))
		}

		if _, ok := prefixMap[prefixSum]; !ok {
			prefixMap[prefixSum] = i
		}

	}

	return maxLen
}

func FindLongestSubArrayGivenNumTwoPointer(arr []int, sum int) int {
	maxLen := 0
	n := len(arr)
	left := 0
	right := 0
	k := arr[0]

	for right < n {
		for left <= right && k > sum {
			k -= arr[left]
			left++
		}

		if k == sum {
			maxLen = int(math.Max(float64(maxLen), float64(right-left+1)))
		}

		right++
		if right < n {
			k += arr[right]
		}
	}

	return maxLen
}
