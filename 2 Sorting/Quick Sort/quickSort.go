package main

import "fmt"

func main() {
	arr := []int{13, 46, 24, 52, 20, 9}
	quickSort(&arr, 0, len(arr)-1)
	printArray(arr)
}

func findPartition(arr *[]int, low, high int) int {
	pivot := (*arr)[low]
	i := low
	j := high

	for i < j {
		for i < high && (*arr)[i] <= pivot {
			i++
		}

		for j > low && (*arr)[j] >= pivot {
			j--
		}

		if i < j {
			temp := (*arr)[i]
			(*arr)[i] = (*arr)[j]
			(*arr)[j] = temp
		}
	}

	temp := (*arr)[low]
	(*arr)[low] = (*arr)[j]
	(*arr)[j] = temp

	return j
}

func quickSort(arr *[]int, low, high int) {
	if low < high {
		partitionIndex := findPartition(arr, low, high)

		quickSort(arr, low, partitionIndex-1)
		quickSort(arr, partitionIndex+1, high)
	}
}

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v ", arr[i])
	}
	fmt.Print("\n")
}
