package subsequencepattern

import "fmt"

// Time :- O(2^N * N)
func PrintAnyOneSubsequenceOfGivenSumK_Recursive(ind int, n int, ds []int, arr []int, sum int, K int) bool {
	if ind >= n {
		if sum == K {
			fmt.Println(ds)
			return true
		} else {
			return false
		}
	}

	sum += arr[ind]
	ds = append(ds, arr[ind])
	if PrintAnyOneSubsequenceOfGivenSumK_Recursive(ind+1, n, ds, arr, sum, K) {
		return true
	}

	sum -= arr[ind]
	ds = append(make([]int, 0, len(ds)), ds[:len(ds)-1]...)
	return PrintAnyOneSubsequenceOfGivenSumK_Recursive(ind+1, n, ds, arr, sum, K)
}
