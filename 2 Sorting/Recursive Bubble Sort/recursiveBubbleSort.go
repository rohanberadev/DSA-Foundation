package main

import "fmt"

func main() {
	arr := []int{13, 46, 24, 52, 20, 9}
	bubbleSortRecursion(&arr, len(arr)-1, 0)
	printArray(arr)
}

func bubbleSortRecursion(arr *[]int, n int, i int) {

	if i == n {
		return
	}

	for i < n {
		if (*arr)[i] > (*arr)[i+1] {
			temp := (*arr)[i]
			(*arr)[i] = (*arr)[i+1]
			(*arr)[i+1] = temp
		}
		i++
	}

	bubbleSortRecursion(arr, n-1, 0)
}

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v ", arr[i])
	}
	fmt.Print("\n")
}
