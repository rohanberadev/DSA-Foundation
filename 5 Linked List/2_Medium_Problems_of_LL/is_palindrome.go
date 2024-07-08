package mediumproblemsofll

import (
	ll "linked_list/1_DS/Singly_Linked_List"
	stack "linked_list/1_DS/Stack"
)

// Time :- O(N) Space :- O(N)
func IsListPalindrome_Brute(ls *ll.LinkedList) bool {
	st := stack.NewStack()

	for node := ls.Head; node != nil; node = node.Next {
		st.Push(node.Data)
	}

	for node := ls.Head; node != nil; node = node.Next {
		if node.Data != st.Pop() {
			return false
		}
	}

	return true
}

func ReverseList(head *ll.Node) *ll.Node {
	if head == nil || head.Next == nil {
		return head
	}

	newHead := ReverseList(head.Next)

	front := head.Next
	front.Next = head
	head.Next = nil

	return newHead
}

func IsListPalindrome_Optimal(ls *ll.LinkedList) bool {
	slow := ls.Head
	fast := ls.Head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	left := ls.Head
	right := ReverseList(slow.Next)

	for right != nil {
		if left.Data != right.Data {
			return false
		}
		left = left.Next
		right = right.Next
	}

	return true
}
