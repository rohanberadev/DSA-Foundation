package mediumproblemsofll

import (
	ll "linked_list/1_DS/Singly_Linked_List"
)

func MergeArr(arr []interface{}, low, mid, high int) {
	left := low
	right := mid + 1

	temp := make([]int, 0, high-low+1)

	for left <= mid && right <= high {
		if arr[left].(int) <= arr[right].(int) {
			temp = append(temp, arr[left].(int))
			left++
		} else {
			temp = append(temp, arr[right].(int))
			right++
		}
	}

	for left <= mid {
		temp = append(temp, arr[left].(int))
		left++
	}

	for right <= high {
		temp = append(temp, arr[right].(int))
		right++
	}

	for i := low; i <= high; i++ {
		arr[i] = temp[i-low]
	}
}

func MergeSortArr(arr []interface{}, low, high int) {
	if low < high {
		mid := (low + high) / 2

		MergeSortArr(arr, low, mid)
		MergeSortArr(arr, mid+1, high)

		MergeArr(arr, low, mid, high)
	}
}

// Time :- O(N Log N + 2N) Space :- O(N)
func MergeSortLL_Brute(ls *ll.LinkedList) {
	// Time :- O(N)
	arr := ll.ConvertLLToArray(ls)
	// Time :- O(N Log N)
	MergeSortArr(arr, 0, len(arr)-1)
	// Time :- O(N)
	i := 0
	for node := ls.Head; node != nil; node = node.Next {
		node.Data = arr[i]
		i++
	}
}

func FindPI(arr []interface{}, low, high int) int {
	pivot := arr[low].(int)
	left := low
	right := high

	for left < right {
		for left < high && arr[left].(int) <= pivot {
			left++
		}

		for right > low && arr[right].(int) >= pivot {
			right--
		}

		if left < right {
			temp := arr[left]
			arr[left] = arr[right]
			arr[right] = temp
		}
	}

	temp := arr[low]
	arr[low] = arr[right]
	arr[right] = temp

	return right
}

func QuickSortArr(arr []interface{}, low, high int) {
	if low < high {
		partitionInd := FindPI(arr, low, high)

		QuickSortArr(arr, low, partitionInd-1)
		QuickSortArr(arr, partitionInd+1, high)
	}
}

// Time :-O(N Log N + 2N) Space :- O(N)
func QuickSortLL_Brute(ls *ll.LinkedList) {
	arr := ll.ConvertLLToArray(ls)
	QuickSortArr(arr, 0, len(arr)-1)

	i := 0
	for node := ls.Head; node != nil; node = node.Next {
		node.Data = arr[i]
		i++
	}
}
