package hard

import (
	"slices"
)

func GenerateHash(arr []int) int {
	n := len(arr)
	hash := 0

	for i := 0; i < n; i++ {
		num := arr[i]
		res := 0
		for num > 0 {
			res *= 10
			res += num % 10
			num /= 10
		}

		for res > 0 {
			hash *= 10
			hash += res % 10
			res /= 10
		}
	}

	return hash
}

// Time :- O(N^4) Space :-
func FourSumBrute(arr []int, target int) [][]int {
	n := len(arr)
	ans := make([][]int, 0, n)
	hashset := make(map[int]bool)

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				for l := k + 1; l < n; l++ {
					sum := arr[i] + arr[j] + arr[k] + arr[l]
					res := []int{arr[i], arr[j], arr[k], arr[l]}
					slices.Sort(res)
					hash := GenerateHash(res)
					// fmt.Println(hash)

					if sum == target && !hashset[hash] {
						ans = append(ans, res)
						hashset[hash] = true
					}
				}
			}
		}
	}

	return ans
}

func FourSumBetter(arr []int, target int) [][]int {
	n := len(arr)
	ans := make([][]int, 0, n)
	hashset := make(map[int]bool)

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			hashmap := make(map[int]bool)
			for k := j + 1; k < n; k++ {
				rem := target - (arr[i] + arr[j] + arr[k])

				if hashmap[rem] {
					res := []int{arr[i], arr[j], arr[k], rem}
					slices.Sort(res)
					hash := GenerateHash(res)

					if !hashset[hash] {
						ans = append(ans, res)
						hashset[hash] = true
					}
				}

				hashmap[arr[k]] = true
			}
		}
	}

	return ans
}

func FourSumOptimal(arr []int, target int) [][]int {
	n := len(arr)
	ans := make([][]int, 0, n)
	slices.Sort(arr)

	for i := 0; i < n; i++ {
		if i != 0 && arr[i] == arr[i-1] {
			continue
		}

		for j := i + 1; j < n; j++ {
			if j > i+1 && arr[j] == arr[j-1] {
				continue
			}

			k := j + 1
			l := n - 1

			for k < l {
				sum := arr[i] + arr[j] + arr[k] + arr[l]

				if sum < target {
					k++

				} else if sum > target {
					l--

				} else {
					res := []int{arr[i], arr[j], arr[k], arr[l]}
					ans = append(ans, res)
					k++
					l--

					for k < l && arr[k] == arr[k-1] {
						k++
					}

					for l > k && arr[l] == arr[l+1] {
						l--
					}

				}
			}
		}
	}

	return ans
}
