package medium

import "fmt"

func LeaderArrayBrute(arr []int) {
	n := len(arr)

	for i := 0; i < n-1; i++ {
		leader := true
		for j := i + 1; j < n; j++ {
			if arr[i] < arr[j] {
				leader = false
				break
			}
		}
		if leader {
			fmt.Printf("%v ", arr[i])
		}
	}

	fmt.Printf("%v \n", arr[n-1])
}

func LeaderArrayOptimal(arr []int) []int {
	n := len(arr)
	maxFromRight := arr[n-1]
	var ans []int

	ans = append(ans, maxFromRight)

	for i := n - 2; i >= 0; i-- {
		if maxFromRight < arr[i] {
			maxFromRight = arr[i]
			ans = append([]int{maxFromRight}, ans...)
		}
	}
	return ans
}
