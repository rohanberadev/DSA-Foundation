package main

import "fmt"

func main() {
	arr := []int{13, 46, 24, 52, 20, 9}
	printArray(insertionSort(arr))
}

func insertionSort(arr []int) []int {
	n := len(arr)

	for i := 0; i < n; i++ {
		j := i
		for j != 0 && arr[j-1] > arr[j] {
			temp := arr[j-1]
			arr[j-1] = arr[j]
			arr[j] = temp
			j--
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
