package mediumproblemsofll

import ll "linked_list/1_DS/Singly_Linked_List"

func add1Recursive(head *ll.Node) int {
	if head == nil {
		return 0
	}
	if head.Next == nil {
		sum := head.Data.(int) + 1
		if sum > 9 {
			head.Data = sum % 10
			carry := sum / 10
			return carry

		} else {
			head.Data = sum
			return 0
		}

	}

	carry := add1Recursive(head.Next)

	sum := head.Data.(int) + carry
	if head.Data.(int) == 9 && carry > 0 {
		head.Data = sum % 10
		carry := sum / 10
		return carry

	} else {
		head.Data = sum
		return 0
	}
}

func Add1ToLL_Recursive(ls *ll.LinkedList) {
	carry := add1Recursive(ls.Head)

	if carry > 0 {
		ls.InsertAtFront(ll.NewNode(carry, nil))
	}
}

func Add1ToLL_Iterative(ls *ll.LinkedList) {
	ReverseLinkedList_Optimal(ls)

	carry := 1
	node := ls.Head

	for node != nil {
		sum := node.Data.(int) + carry

		if sum > 9 {
			node.Data = sum % 10
			carry = sum / 10

		} else {
			node.Data = sum
			carry = 0
		}

		node = node.Next
	}

	ReverseLinkedList_Optimal(ls)

	if carry > 0 {
		ls.InsertAtFront(ll.NewNode(carry, nil))
	}

}
