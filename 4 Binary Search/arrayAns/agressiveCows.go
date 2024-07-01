package arrayans

import (
	"slices"
)

func PossibleCowPlacement(arr []int, k, minDist int) bool {
	lastStall := arr[0]
	cow := 1
	for i := 1; i < len(arr); i++ {
		if arr[i]-lastStall >= minDist {
			lastStall = arr[i]
			cow++
		}
		if cow == k {
			return true
		}
	}

	return false
}

func AgressiveCows_Brute(arr []int, k int) int {
	slices.Sort(arr)
	n := len(arr)
	limit := arr[n-1] - arr[0]

	for i := 1; i <= limit; i++ {
		if !PossibleCowPlacement(arr, k, i) {
			return i - 1
		}
	}

	return limit
}
