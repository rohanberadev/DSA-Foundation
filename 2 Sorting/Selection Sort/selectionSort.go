package main

import "fmt"

func main() {
	arr := []int{13, 46, 24, 52, 20, 9}
	printArray(selectionSort(arr))
}

func selectionSort(arr []int) []int {
	n := len(arr)

	for i := 0; i < n-1; i++ {
		mini := i
		for j := i + 1; j < n; j++ {
			if arr[j] < arr[mini] {
				mini = j
			}
		}
		temp := arr[i]
		arr[i] = arr[mini]
		arr[mini] = temp
	}

	return arr
}

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v ", arr[i])
	}
	fmt.Print("\n")
}
