package array

import "fmt"

func PrintArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v ", arr[i])
	}
	fmt.Print("\n")
}
