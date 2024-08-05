package hard

import (
	"slices"
)

// Time :- O(N^3) Space :- O(N)
func ThreeSumMySelf(arr []int) [][]int {
	n := len(arr)
	ans := make([][]int, 0, n)
	numMap := make(map[int]bool)

	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			sum := arr[i] + arr[j]
			rem := -1 * sum
			found := LinearSearch(arr, rem)

			if found != -1 && found != i && found != j {
				if CheckForUnique(numMap, arr[i], arr[j], rem) {
					res := []int{arr[i], arr[j], rem}
					slices.Sort(res)
					ans = append(ans, res)

					numMap[arr[i]] = true
					numMap[arr[j]] = true
					numMap[rem] = true
				}
			}
		}
	}

	return ans
}

func LinearSearch(arr []int, target int) int {
	for i := 0; i < len(arr); i++ {
		if arr[i] == target {
			return i
		}
	}

	return -1
}

func CheckForUnique(m map[int]bool, i, j, k int) bool {
	count := 0

	if m[i] {
		count++
	}

	if m[j] {
		count++
	}

	if m[k] {
		count++
	}

	if count == 3 {
		return false
	}

	return true
}

// Time :- O(N^3) Space :- O(N) for unique
func ThreeSumBrute(arr []int) [][]int {
	n := len(arr)
	ans := make([][]int, 0, n)
	numMap := make(map[int]bool)

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				if arr[i]+arr[j]+arr[k] == 0 {
					if CheckForUnique(numMap, arr[i], arr[j], arr[k]) {
						numMap[arr[i]] = true
						numMap[arr[j]] = true
						numMap[arr[k]] = true

						res := []int{arr[i], arr[j], arr[k]}
						slices.Sort(res)
						ans = append(ans, res)
					}
				}
			}
		}
	}

	return ans
}

// Time :- O(N^2) Space :- For ds
func ThreeSumBetter(arr []int) [][]int {
	n := len(arr)
	ans := make([][]int, 0, n)
	numMap := make(map[int]bool)

	for i := 0; i < n; i++ {
		hashMap := make(map[int]bool)

		for j := i + 1; j < n; j++ {
			third := -(arr[i] + arr[j])

			if _, ok := hashMap[third]; ok {
				if CheckForUnique(numMap, arr[i], arr[j], third) {
					res := []int{arr[i], arr[j], third}
					slices.Sort(res)
					ans = append(ans, res)

					numMap[arr[i]] = true
					numMap[arr[j]] = true
					numMap[third] = true
				}
			}
			hashMap[arr[j]] = true
		}
	}

	return ans
}

// Time :- O(N^2 + N Log N)
func ThreeSumOptimal(arr []int) [][]int {
	n := len(arr)
	ans := make([][]int, 0, n)

	slices.Sort(arr)

	for i := 0; i < n; i++ {
		if i != 0 && arr[i-1] == arr[i] {
			continue
		}

		j := i + 1
		k := n - 1

		for j < k {
			sum := arr[i] + arr[j] + arr[k]

			if sum < 0 {
				j++

			} else if sum > 0 {
				k--

			} else {
				res := []int{arr[i], arr[j], arr[k]}
				ans = append(ans, res)
				j++
				k--

				for j < k && arr[j] == arr[j-1] {
					j++
				}

				for k > j && arr[k] == arr[k+1] {
					k--
				}
			}

		}
	}

	return ans
}
