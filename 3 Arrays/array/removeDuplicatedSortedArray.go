package array

import "fmt"

func RemoveDuplicatesSortedArray(arr []int) {
	n := len(arr)
	j := 0

	for i := 1; i < n; i++ {
		if arr[j] != arr[i] {
			j++
			arr[j] = arr[i]
		}
	}

	for i := 0; i <= j; i++ {
		fmt.Printf("%v ", arr[i])
	}
	fmt.Print("\n")
}
