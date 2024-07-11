package hardproblemsofll

import (
	ll "linked_list/1_DS/Singly_Linked_List"
)

func converLLToArr(head *ll.Node) []interface{} {
	arr := make([]interface{}, 0, 100)

	for node := head; node != nil; node = node.Next {
		arr = append(arr, node.Data)
	}

	return arr
}

func converArrToLL(arr []interface{}) *ll.LinkedList {
	ls := ll.NewEmptyList()

	for i := 0; i < len(arr); i++ {
		ls.InsertAtBack(ll.NewNode(arr[i], nil))
	}

	return ls
}

func mergeArr(arr []interface{}, low, mid, high int) {
	left := low
	right := mid + 1

	temp := make([]interface{}, 0, high-low+1)

	for left <= mid && right <= high {
		if arr[left].(int) <= arr[right].(int) {
			temp = append(temp, arr[left])
			left++

		} else {
			temp = append(temp, arr[right])
			right++
		}
	}

	for left <= mid {
		temp = append(temp, arr[left])
		left++
	}

	for right <= high {
		temp = append(temp, arr[right])
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

		mergeArr(arr, low, mid, high)
	}
}

func FlattenLL_Brute(head *NodeWithChild) *ll.LinkedList {
	dummy := ll.NewNode(nil, nil)
	temp := dummy

	for node := head; node != nil; node = node.Next {
		temp.Next = ll.NewNode(node.Data, nil)
		temp = temp.Next

		for child := node.Child; child != nil; child = child.Child {
			temp.Next = ll.NewNode(child.Data, nil)
			temp = temp.Next
		}
	}

	arr := converLLToArr(dummy.Next)

	MergeSortArr(arr, 0, len(arr)-1)

	ls := converArrToLL(arr)

	return ls
}
