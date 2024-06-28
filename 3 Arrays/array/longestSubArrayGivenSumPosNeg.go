package array

import "math"

// Time :- O(N^3) Space:- O(1)
func FindLongestSubArrayPosNegGivenNumBrute(arr []int, sum int) int {
	maxLen := 0
	n := len(arr)

	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			k := 0

			for K := i; K <= j; K++ {
				k += arr[K]
			}

			if k == sum {
				maxLen = int(math.Max(float64(maxLen), float64(j-i+1)))
			}
		}
	}

	return maxLen
}

// Time :- O(N^2) Space:- O(1)
func FindLongestSubArrayPosNegGivenNumBetter(arr []int, sum int) int {
	maxLen := 0
	n := len(arr)

	for i := 0; i < n-1; i++ {
		k := 0
		for j := i; j < n; j++ {
			k += arr[j]
			if sum == k {
				maxLen = int(math.Max(float64(maxLen), float64(j-i+1)))
			}
		}
	}

	return maxLen
}

func FindLongestSubArrayPosNegGivenNumHashing(arr []int, sum int) int {
	n := len(arr)
	N := math.MaxInt64
	maxLen := 0
	prefixMap := make(map[int]int, N)
	prefixSum := 0

	for i := 0; i < n; i++ {
		prefixSum += arr[i]

		if prefixSum == sum {
			maxLen = int(math.Max(float64(maxLen), float64(i+1)))
		}

		rem := prefixSum - sum
		if val, ok := prefixMap[rem]; ok {
			maxLen = int(math.Max(float64(maxLen), float64(i-val)))
		}

		prefixMap[prefixSum] = i
	}

	return maxLen
}
