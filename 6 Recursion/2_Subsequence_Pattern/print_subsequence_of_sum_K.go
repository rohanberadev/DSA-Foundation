package subsequencepattern

import "fmt"

// Time :- O(2^N) Space :- O(N)
func PrintSubsequence_Sum_K_Recursive(ind int, n int, ds []int, arr []int, sum int, K int) {
	if ind >= n {
		if sum == K {
			fmt.Println(ds)
		}
		return
	}

	sum += arr[ind]
	ds = append(ds, arr[ind])
	PrintSubsequence_Sum_K_Recursive(ind+1, n, ds, arr, sum, K)

	sum -= arr[ind]
	ds = append(make([]int, 0, len(ds)), ds[:len(ds)-1]...)
	PrintSubsequence_Sum_K_Recursive(ind+1, n, ds, arr, sum, K)
}

// Time :- O(2^N * N) Space :- O(1)
func PrintSubsequence_Sum_K_PowerSet(arr []int, n int, K int) {
	for num := 0; num < (1 << n); num++ {
		ds := make([]int, 0, n)
		sum := 0
		for i := 0; i < n; i++ {
			if num&(1<<i) != 0 {
				ds = append(ds, arr[i])
				sum += arr[i]
			}
		}
		if sum == K {
			fmt.Println(ds)
		}
	}
}
