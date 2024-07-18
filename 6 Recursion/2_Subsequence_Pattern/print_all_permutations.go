package subsequencepattern

// Time :- O(N!) Space :- O(2N) for using ds and freq.
func PrintAllPermutations_MapTechnique(arr []int, ds []int, freq []bool, n int) [][]int {
	ans := make([][]int, 0, len(ds))

	if len(ds) == n {
		res := make([]int, 0, len(ds))
		res = append(res, ds...)
		ans = append(ans, res)
		return ans

	}

	for i := 0; i < n; i++ {
		if !freq[i] {
			freq[i] = true
			ds = append(ds, arr[i])

			ans = append(ans, PrintAllPermutations_MapTechnique(arr, ds, freq, n)...)

			freq[i] = false
			ds = append(make([]int, 0, len(ds)), ds[:len(ds)-1]...)
		}
	}

	return ans
}

// Time :- O(N!) Space :- O(1)
func PrintAllPermutations_PointersTechnique(arr []int, ind int, n int) [][]int {
	ans := make([][]int, 0, n)

	if ind >= n {
		res := make([]int, 0, n)
		res = append(res, arr...)
		ans = append(ans, res)
		return ans
	}

	for i := 0; i <= ind; i++ {
		arr[i], arr[ind] = arr[ind], arr[i]

		ans = append(ans, PrintAllPermutations_PointersTechnique(arr, ind+1, n)...)

		arr[ind], arr[i] = arr[i], arr[ind]
	}

	return ans
}
