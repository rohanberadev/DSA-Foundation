package mediumproblemsofll

import (
	queue "linked_list/1_DS/Queue"
	ll "linked_list/1_DS/Singly_Linked_List"
)

// Time :- O(N) Space :- O(N)
func SegregateEvenAndOdd_Brute(ls *ll.LinkedList) *ll.LinkedList {
	even := queue.NewQueue()
	odd := queue.NewQueue()

	for node := ls.Head; node != nil; node = node.Next {
		if node.Data.(int)%2 == 0 {
			even.Enqueue(node.Data)
		} else {
			odd.Enqueue(node.Data)
		}
	}
	node := ls.Head
	for !even.IsEmpty() {
		node.Data = even.Dequeue()
		node = node.Next
	}

	for !odd.IsEmpty() {
		node.Data = odd.Dequeue()
		node = node.Next
	}

	return ls
}

// Time :- O(N) Space :- O(1)
func SegregateEvenAndOdd_Optimal(ls *ll.LinkedList) *ll.Node {
	var evenHead, oddHead, evenTail, oddTail *ll.Node

	for node := ls.Head; node != nil; node = node.Next {
		if node.Data.(int)&1 == 1 {
			if oddHead == nil {
				oddHead = ll.NewNode(node.Data, nil)
				oddTail = oddHead
			} else {
				oddTail.Next = ll.NewNode(node.Data, nil)
				oddTail = oddTail.Next
			}

		} else {
			if evenHead == nil {
				evenHead = ll.NewNode(node.Data, nil)
				evenTail = evenHead
			} else {
				evenTail.Next = ll.NewNode(node.Data, nil)
				evenTail = evenTail.Next
			}
		}
	}

	evenTail.Next = oddHead
	return evenHead
}
