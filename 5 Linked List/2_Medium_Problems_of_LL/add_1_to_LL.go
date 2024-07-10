package mediumproblemsofll

import ll "linked_list/1_DS/Singly_Linked_List"

func add1Recursive(head *ll.Node) int {
	if head == nil {
		return 0
	}
	if head.Next == nil {
		if head.Data.(int) == 9 {
			head.Data = 0
			return 1
		} else {
			head.Data = head.Data.(int) + 1
			return 0
		}

	}

	carry := add1Recursive(head.Next)

	if head.Data.(int) == 9 && carry > 0 {
		head.Data = 0
		return 1
	} else {
		head.Data = head.Data.(int) + carry
		return 0
	}
}

func Add1ToLL(ls *ll.LinkedList) {
	carry := add1Recursive(ls.Head)

	if carry > 0 {
		ls.InsertAtFront(ll.NewNode(carry, nil))
	}
}
