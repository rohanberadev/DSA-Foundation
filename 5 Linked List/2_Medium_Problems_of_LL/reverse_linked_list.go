package mediumproblemsofll

import (
	ll "linked_list/1_DS/Singly_Linked_List"
	stack "linked_list/1_DS/Stack"
)

// Time :- O(N) // Space :- O(N)
func ReverseLinkedList_Brute(ls *ll.LinkedList) {
	st := stack.NewStack()

	for node := ls.Head; node != nil; node = node.Next {
		st.Push(node.Data)
	}

	for node := ls.Head; node != nil; node = node.Next {
		node.Data = st.Pop()
	}
}

// Time :- O(N) // Space :- O(1)
func ReverseLinkedList_Optimal(ls *ll.LinkedList) {
	mover := ls.Head
	ls.Tail = mover
	var prev *ll.Node
	var next *ll.Node

	for mover != nil {
		next = mover.Next
		mover.Next = prev
		prev = mover
		mover = next
	}

	ls.Head = prev
}

func Reverse_Recursive(head *ll.Node) []*ll.Node {
	if head == nil || head.Next == nil {
		return []*ll.Node{head, head}
	}

	newHead := Reverse_Recursive(head.Next)[0]

	front := head.Next
	front.Next = head
	head.Next = nil

	return []*ll.Node{newHead, front}
}

// Time :- O(N) Space :- O(1)
func ReverseLinkedList_Recursive(ls *ll.LinkedList) {
	ans := Reverse_Recursive(ls.Head)
	ls.Head = ans[0]
	ls.Tail = ans[1]
}
