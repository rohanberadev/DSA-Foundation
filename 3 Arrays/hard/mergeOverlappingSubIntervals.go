package hard

import (
	"math"
	"sort"
)

func Sort2DArray(arr [][]int) {
	sort.Slice(arr, func(i, j int) bool {
		for k := 0; k < len(arr[i]) && k < len(arr[j]); k++ {
			if arr[i][k] != arr[j][k] {
				return arr[i][k] < arr[j][k]
			}
		}

		return len(arr[i]) < len(arr[j])
	})
}

// Time :- O(N Log N + 2N) Time :- O(N)
func MergeOverlappingSubIntervalBrute(arr [][]int) [][]int {
	n := len(arr)
	ans := make([][]int, 0, n)
	t := -1

	Sort2DArray(arr)

	for i := 0; i < n; i++ {
		start := arr[i][0]
		end := arr[i][1]

		if t >= 0 && ans[t][1] >= arr[i][1] {
			continue
		}

		for j := i + 1; j < n; j++ {
			if arr[j][0] <= end {
				end = int(math.Max(float64(end), float64(arr[j][1])))

			} else {
				break
			}
		}

		ans = append(ans, []int{start, end})
		t++
	}

	return ans
}

// Time :- O(N Log N + N) Space :- O(N)
func MergeOverlappingSubIntervalOptimal(arr [][]int) [][]int {
	n := len(arr)
	ans := make([][]int, 0, n)

	Sort2DArray(arr)

	start := arr[0][0]
	end := arr[0][1]

	for i := 1; i < n; i++ {
		if arr[i][0] <= end {
			end = int(math.Max(float64(end), float64(arr[i][1])))

		} else {
			ans = append(ans, []int{start, end})
			start = arr[i][0]
			end = arr[i][1]
		}
	}

	ans = append(ans, []int{start, end})

	return ans
}
