package subsequencepattern

import (
	ds "Recursion/DS"
	"fmt"
)

// Time :- O(2^N * N) Space :- O(N)
func PrintAllSubsequences_Recursive(ind int, n int, arr []int, ls *ds.List) {
	if ind >= n {
		ls.Print()
		return
	}

	// take or pick the particular element in the subsequence.
	ls.Push_back(arr[ind])
	PrintAllSubsequences_Recursive(ind+1, n, arr, ls)

	// don't take or pick the particular element in the subsequence.
	ls.Pop_Back()
	PrintAllSubsequences_Recursive(ind+1, n, arr, ls)
}

// Time :- O(2^N * N) Space :- O(1)
func PrintAllSubsequences_PowerSet(arr []int, n int) {
	for num := 0; num < (1 << n); num++ {
		ans := make([]int, 0, n)

		for i := 0; i < n; i++ {
			if num&(1<<i) != 0 {
				ans = append(ans, arr[i])
			}
		}
		fmt.Println(ans)
	}
}
