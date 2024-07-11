package mediumproblemsofdll

import (
	dll "linked_list/1_DS/Doubly_Linked_List"
)

// Time :- O(N) Space :- O(N)
func RemoveDuplicatesLL_Hashing(dls *dll.DoubleLinkedList) {
	mpp := make(map[int]bool)
	dummy := dll.NewDoublyNode(nil, nil, nil)
	curr := dummy

	for node := dls.Head; node != nil; node = node.Next {
		if !mpp[node.Data.(int)] {
			curr.Next = node
			curr = curr.Next
		}

		mpp[node.Data.(int)] = true
	}

	dls.Head = dummy.Next
	dls.Tail = curr
	curr.Next = nil
}

// Time :- O(N) Space :- O(N)
func RemoveDuplicatesLL_Optimal(dls *dll.DoubleLinkedList) {
	tempNode := dls.Head

	for tempNode != nil {
		nextNode := tempNode.Next

		for nextNode != nil && nextNode.Data.(int) == tempNode.Data.(int) {
			nextNode = nextNode.Next
		}

		tempNode.Next = nextNode
		if nextNode != nil {
			nextNode.Prev = tempNode
		}

		tempNode = tempNode.Next
	}
}
