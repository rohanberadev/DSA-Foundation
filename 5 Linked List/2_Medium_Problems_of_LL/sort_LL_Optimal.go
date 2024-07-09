package mediumproblemsofll

import (
	ll "linked_list/1_DS/Singly_Linked_List"
)

func findMid(head *ll.Node) *ll.Node {
	if head == nil || head.Next == nil {
		return head
	}

	slow := head
	fast := head.Next

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	return slow
}

func mergeLL(left, right *ll.Node) *ll.Node {
	dummy := ll.NewNode(nil, nil)
	current := dummy

	for left != nil && right != nil {
		if left.Data.(int) <= right.Data.(int) {
			current.Next = left
			left = left.Next

		} else {
			current.Next = right
			right = right.Next
		}
		current = current.Next
	}

	if left != nil {
		current.Next = left
	} else {
		current.Next = right
	}

	return dummy.Next
}

func mergeSortLL(head *ll.Node) *ll.Node {
	if head == nil || head.Next == nil {
		return head
	}

	mid := findMid(head)
	left := head
	right := mid.Next
	mid.Next = nil

	left = mergeSortLL(left)
	right = mergeSortLL(right)

	return mergeLL(left, right)
}

func MergeSortLL_Optimal(ls *ll.LinkedList) {
	ls.Head = mergeSortLL(ls.Head)
}
