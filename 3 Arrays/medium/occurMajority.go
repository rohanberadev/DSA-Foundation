package medium

import (
	"math"
)

func OccurmajorityBrute(arr []int) int {
	n := len(arr)

	for i := 0; i < n-1; i++ {
		count := 1
		for j := i + 1; j < n; j++ {
			if arr[i] == arr[j] {
				count++
			}
		}

		if count > int(n/2) {
			return arr[i]
		}
	}

	return -1
}

func OccurMajorityHashing(arr []int) int {
	n := len(arr)
	N := 0
	for i := 0; i < n; i++ {
		N = int(math.Max(float64(arr[i]), float64(N)))
	}

	hashmap := make(map[int]int, N+1)

	for i := 0; i < n; i++ {
		hashmap[arr[i]] += 1
	}

	for i := 0; i <= N; i++ {
		if hashmap[i] > int(n/2) {
			return i
		}
	}

	return -1
}

func OccurMajorityMooresVoting(arr []int) int {
	element := -1
	count := 0
	n := len(arr)

	for i := 0; i < n; i++ {
		if count == 0 {
			element = arr[i]
			count = 1

		} else if arr[i] == element {
			count++

		} else {
			count--
		}

	}

	return element
}
