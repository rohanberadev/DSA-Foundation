package mediumproblemsofdll

import dll "linked_list/1_DS/Doubly_Linked_List"

func DeleteOccurences(dls *dll.DoubleLinkedList, key int) {
	node := dls.Head

	for node != nil {
		if node.Data.(int) == key {
			if node == dls.Head {
				dls.Head = node.Next
				dls.Head.Prev = nil

			} else if node.Next == nil {
				dls.Tail = node.Prev
				dls.Tail.Next = nil

			} else {
				node.Prev.Next = node.Next
				node.Next.Prev = node.Prev
			}
		}

		node = node.Next
	}
}
