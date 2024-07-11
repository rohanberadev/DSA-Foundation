package hardproblemsofll

import (
	ll "linked_list/1_DS/Singly_Linked_List"
)

func getKthElem(head *ll.Node, k int) *ll.Node {
	node := head
	k--

	for node != nil && k > 0 {
		k--
		node = node.Next
	}

	return node
}

func reverse(head *ll.Node) {
	node := head
	var prev *ll.Node
	var next *ll.Node

	for node != nil {
		next = node.Next
		node.Next = prev
		prev = node
		node = next
	}
}

func ReverseGivenSizeLL(ls *ll.LinkedList, k int) {
	node := ls.Head
	var prevLast *ll.Node

	for node != nil {
		kThNode := getKthElem(node, k)

		if kThNode == nil {
			if prevLast != nil {
				prevLast.Next = node
			}
			break
		}

		next := kThNode.Next
		kThNode.Next = nil

		reverse(node)

		if node == ls.Head {
			ls.Head = kThNode
		} else {
			prevLast.Next = kThNode
		}

		prevLast = node
		node = next
	}

	// setting tail.
	if prevLast.Next != nil {
		for node := prevLast; node != nil; node = node.Next {
			if node.Next != nil {
				ls.Tail = node
			}
		}
	} else {
		ls.Tail = prevLast
	}
}
