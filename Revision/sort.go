package main

import "fmt"

func main() {
	arr := []int{13, 46, 24, 52, 20, 9}
	// fmt.Println(selectionSort(arr))
	// fmt.Println(bubbleSort(arr))
	// fmt.Println(insertionSort(arr))
	// mergeSort(&arr, 0, len(arr)-1)
	// fmt.Println(arr)
	// quickSort(&arr, 0, len(arr)-1)
	fmt.Println(arr)
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
		temp := arr[mini]
		arr[mini] = arr[i]
		arr[i] = temp
	}

	return arr
}

func bubbleSort(arr []int) []int {
	n := len(arr)

	for i := n - 1; i >= 0; i-- {
		checkSwap := false
		for j := 0; j < i; j++ {
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

func mergeSort(arr *[]int, low, high int) {
	if low >= high {
		return
	}

	mid := (low + high) / 2

	mergeSort(arr, low, mid)
	mergeSort(arr, mid+1, high)

	merge(arr, low, mid, high)
}

func insertionSort(arr []int) []int {
	n := len(arr)

	for i := 0; i < n; i++ {
		j := i
		for j > 0 && arr[j] < arr[j-1] {
			temp := arr[j]
			arr[j] = arr[j-1]
			arr[j-1] = temp
			j--
		}
	}

	return arr
}

func merge(arr *[]int, low, mid, high int) {
	n := mid - low + high - mid + 2
	left := low
	right := mid + 1
	temp := make([]int, 0, n)

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

	for i := low; i <= high; i++ {
		(*arr)[i] = temp[i-low]
	}
}

func findPartition(arr *[]int, low, high int) int {
	pivot := (*arr)[low]
	left := low
	right := high

	for left < right {
		for left < high && pivot >= (*arr)[left] {
			left++
		}

		for right > low && pivot <= (*arr)[right] {
			right--
		}

		if left < right {
			temp := (*arr)[left]
			(*arr)[left] = (*arr)[right]
			(*arr)[right] = temp
		}
	}

	temp := (*arr)[low]
	(*arr)[low] = (*arr)[right]
	(*arr)[right] = temp

	return right
}

func quickSort(arr *[]int, low, high int) {
	if low < high {
		parition := findPartition(arr, low, high)

		quickSort(arr, low, parition-1)
		quickSort(arr, parition+1, high)
	}
}
