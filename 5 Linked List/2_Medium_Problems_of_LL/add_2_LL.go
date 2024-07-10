package mediumproblemsofll

import ll "linked_list/1_DS/Singly_Linked_List"

// Time :- O(max(m,n)) Space :- O(max(m,n))
func Add2Numbers(ls1 *ll.LinkedList, ls2 *ll.LinkedList) *ll.Node {
	head := ll.NewNode(nil, nil)
	curr := head
	carry := 0

	node1 := ls1.Head
	node2 := ls2.Head

	for (node1 != nil || node2 != nil) || carry > 0 {
		sum := 0
		if node1 != nil {
			sum += node1.Data.(int)
			node1 = node1.Next
		}

		if node2 != nil {
			sum += node2.Data.(int)
			node2 = node2.Next
		}

		sum += carry
		carry = sum / 10
		curr.Next = ll.NewNode(sum%10, nil)
		curr = curr.Next
	}

	return head.Next
}
