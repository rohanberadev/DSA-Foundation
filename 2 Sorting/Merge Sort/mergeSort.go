package main

import "fmt"

func main() {
	arr := []int{3, 2, 8, 5, 1, 4, 23}
	mergeSort(&arr, 0, len(arr)-1)
	printArray(arr)
}

func mergeSort(arr *[]int, low int, high int) {
	if low >= high {
		return
	}

	var mid int = (low + high) / 2

	mergeSort(arr, low, mid)
	mergeSort(arr, mid+1, high)

	merge(arr, low, mid, high)

}

func merge(arr *[]int, low int, mid int, high int) {
	left := low
	right := mid + 1
	temp := make([]int, 0, high-low+1)

	for left <= mid && right <= high {
		if (*arr)[left] <= (*arr)[right] {
			temp = append(temp, (*arr)[left])
			left++
		} else {
			temp = append(temp, (*arr)[right])
			right++
		}
	}

	for left <= mid {
		temp = append(temp, (*arr)[left])
		left++
	}

	for right <= high {
		temp = append(temp, (*arr)[right])
		right++
	}

	for i := 0; i < len(temp); i++ {
		(*arr)[low+i] = temp[i]
	}

}

func printArray(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Printf("%v ", arr[i])
	}
	fmt.Print("\n")
}
