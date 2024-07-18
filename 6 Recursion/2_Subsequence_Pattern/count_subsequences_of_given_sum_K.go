package subsequencepattern

func CountSubsequencesOfGivenSumK_Recursive(ind int, n int, arr []int, sum int, K int) int {
	count := 0

	if ind >= n {
		if sum == K {
			return 1
		} else {
			return 0
		}
	}

	sum += arr[ind]
	count += CountSubsequencesOfGivenSumK_Recursive(ind+1, n, arr, sum, K)

	sum -= arr[ind]
	count += CountSubsequencesOfGivenSumK_Recursive(ind+1, n, arr, sum, K)

	return count
}
