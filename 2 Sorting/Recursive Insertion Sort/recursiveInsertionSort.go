package main

import "fmt"

func main() {
	arr := []int{13, 46, 24, 52, 20, 9}
	insertionSortRecursion(&arr, len(arr)-1, 0)
	printArray(arr)
}

func insertionSortRecursion(arr *[]int, n, i int) {
	j := i
	for j > 0 && (*arr)[j-1] > (*arr)[j] {
		temp := (*arr)[j]
		(*arr)[j] = (*arr)[j-1]
		(*arr)[j-1] = temp
		j--
	}

	if i == n {
		return
	}

	insertionSortRecursion(arr, n, i+1)
}

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v ", arr[i])
	}
	fmt.Print("\n")
}
