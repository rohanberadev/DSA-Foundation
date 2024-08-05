package hard

import "math"

func LengthLongestSubArrayWithSum0Brute(arr []int) int {
	n := len(arr)
	maxLen := 0

	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			sum := 0

			for k := i; k <= j; k++ {
				sum += arr[k]
			}

			if sum == 0 {
				maxLen = int(math.Max(float64(maxLen), float64(j-i+1)))
			}
		}
	}

	return maxLen
}

func LengthLongestSubArrayWithSum0Better(arr []int) int {
	n := len(arr)
	maxLen := 0

	for i := 0; i < n; i++ {
		sum := 0
		for j := i; j < n; j++ {
			sum += arr[j]

			if sum == 0 {
				maxLen = int(math.Max(float64(maxLen), float64(j-i+1)))
			}
		}
	}

	return maxLen
}

func LengthLongestSubArrayWithSum0Hashing(arr []int) int {
	n := len(arr)
	maxLen := 0
	prefixMap := make(map[int]int)
	prefixSum := 0

	for i := 0; i < n; i++ {
		prefixSum += arr[i]

		if prefixSum == 0 {
			maxLen = int(math.Max(float64(maxLen), float64(i+1)))
		}

		rem := prefixSum - 0

		if val, ok := prefixMap[rem]; ok {
			if i-val > maxLen {
				maxLen = i - val
			}
		}

		if _, ok := prefixMap[prefixSum]; !ok {
			prefixMap[prefixSum] = i
		}
	}

	return maxLen
}
