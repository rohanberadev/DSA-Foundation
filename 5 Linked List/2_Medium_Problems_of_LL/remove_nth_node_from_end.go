package mediumproblemsofll

import (
	ll "linked_list/1_DS/Singly_Linked_List"
)

// Time :- O(L + L-N) Space :- O(1)
func RemoveNthNodeFromEnd_Brute(ls *ll.LinkedList, n int) *ll.Node {
	size := ls.Size()

	if size < n || ls.Head == nil {
		return nil
	}

	res := size - n

	if res == 0 {
		head := ls.Head
		ls.Head = head.Next
		head.Next = nil
		return head
	}

	node := ls.Head
	for i := 1; i < res; i++ {
		node = node.Next
	}

	delNode := node.Next
	node.Next = node.Next.Next
	delNode.Next = nil

	return delNode
}

// Time :- O(n) Space :- O(1)
func RemoveNthNodeFromEnd_Optimal(ls *ll.LinkedList, n int) *ll.Node {
	slow := ls.Head
	fast := ls.Head

	i := 0

	for i < n && fast != nil {
		fast = fast.Next
		i++
	}

	// size < n
	if i < n {
		return nil
	}

	// size == n
	if fast == nil {
		ls.Head = slow.Next
		slow.Next = nil
		return slow
	}

	for fast.Next != nil {
		slow = slow.Next
		fast = fast.Next
	}

	delNode := slow.Next
	slow.Next = slow.Next.Next
	delNode.Next = nil

	return delNode
}
