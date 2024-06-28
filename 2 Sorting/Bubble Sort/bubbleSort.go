package main

import "fmt"

func main() {
	arr := []int{13, 46, 24, 52, 20, 9}
	printArray(bubbleSort(arr))
}

func bubbleSort(arr []int) []int {
	n := len(arr)

	for i := n - 1; i >= 0; i-- {
		for j := 0; j <= i-1; j++ {
			if arr[j] > arr[j+1] {
				temp := arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp
			}
		}
	}

	return arr
}

// From this, the best case scenario will be O(N)
func bubbleSortOptimal(arr []int) []int {
	n := len(arr)

	for i := n - 1; i >= 0; i-- {
		checkSwap := false
		for j := 0; j <= i-1; j++ {
			if arr[j] > arr[j+1] {
				temp := arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp
				checkSwap = true
			}
		}
		if !checkSwap {
			break
		}
	}

	return arr
}

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v ", arr[i])
	}
	fmt.Print("\n")
}
