package medium

import "myArray/array"

func LinearSearch(arr []int, k int) bool {
	n := len(arr)

	for i := 0; i < n; i++ {
		if arr[i] == k {
			return true
		}
	}

	return false
}

// Time :- O(N^2) Space :- O(1)
func MaximumConsecutiveNumBrute(arr []int) int {
	maxConsec := 1
	n := len(arr)

	for i := 0; i < n; i++ {
		currenNum := arr[i]
		count := 1

		for LinearSearch(arr, currenNum+1) {
			count++
			currenNum++
		}

		if maxConsec < count {
			maxConsec = count
		}
	}

	return maxConsec
}

// Time :- O(N Log N) Space :- O(1)
func MaximumConsecutiveNumBetter(arr []int) int {
	maxConsec := 1
	n := len(arr)

	array.MergeSort(&arr, 0, n-1)
	count := 1
	for i := 0; i < n-1; i++ {
		if arr[i+1]-arr[i] == 1 {
			count++
			if maxConsec < count {
				maxConsec = count
			}

		} else {
			count = 1
		}
	}

	return maxConsec
}

// Time :- O(N) Space :- O(N). Here N is the max number in the array.
func MaximumConsecutiveNumOptimal(arr []int) int {
	n := len(arr)
	maxConsec := 1
	numMap := make(map[int]bool)

	for i := 0; i < n; i++ {
		numMap[arr[i]] = true
	}

	for i := 0; i < n; i++ {
		currenNum := arr[i]
		count := 1

		for numMap[currenNum+1] {
			currenNum++
			count++
		}

		if maxConsec < count {
			maxConsec = count
		}
	}

	return maxConsec
}
