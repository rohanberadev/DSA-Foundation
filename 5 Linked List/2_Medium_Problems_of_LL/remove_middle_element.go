package mediumproblemsofll

import ll "linked_list/1_DS/Singly_Linked_List"

// Time :- O(N + (N/2)) Space :- O(1)
func RemoveMiddleElement_Brute(ls *ll.LinkedList) *ll.Node {
	size := ls.Size()
	n := size / 2

	node := ls.Head

	for i := 1; i < n; i++ {
		node = node.Next
	}

	delNode := node.Next
	node.Next = node.Next.Next

	return delNode
}

// Time :- O(N) Space :- O(1)
func RemoveMiddleElement_Optimal(ls *ll.LinkedList) *ll.Node {
	slow := ls.Head
	fast := ls.Head

	fast = fast.Next.Next
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	delNode := slow.Next
	slow.Next = slow.Next.Next
	delNode.Next = nil

	return delNode
}
