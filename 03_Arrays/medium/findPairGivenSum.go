package medium

import "math"

// Time :- O(N^2) Space :- O(1)
func FindPairGivenSumBrute(arr []int, k int) []int {
	res := make([]int, 2)
	res[0] = -1
	res[1] = -1

	n := len(arr)

	for i := 0; i < n-1; i++ {
		for j := i; j < n; j++ {
			if arr[i]+arr[j] == k {
				res[0] = i
				res[1] = j
				return res
			}
		}
	}

	return res
}

// Time :- O(N) Space :- O(N)
func FindPairGivenSumHashing(arr []int, k int) []int {
	n := len(arr)
	res := make([]int, 2)
	hashmap := make(map[int]int, math.MaxInt64)
	res[0] = -1
	res[1] = -1

	for i := 0; i < n; i++ {
		key := k - arr[i]

		if _, ok := hashmap[key]; ok {
			res[0] = key
			res[1] = arr[i]
			return res
		}

		hashmap[arr[i]] = i
	}

	return res
}

// Time :- O(N) Space :- O(1)
func FindPairGivenSumSorted(arr []int, k int) []int {
	res := make([]int, 2)
	res[0] = -1
	res[1] = -1
	left := 0
	right := len(arr) - 1

	for left < right {
		sum := arr[left] + arr[right]

		if sum == k {
			res[0] = left
			res[1] = right
			return res

		} else if sum < k {
			left++
		} else {
			right--
		}
	}

	return res
}
