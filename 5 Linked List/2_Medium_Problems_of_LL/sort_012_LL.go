package mediumproblemsofll

import (
	ll "linked_list/1_DS/Singly_Linked_List"
)

// Time :- O(2*N) Space :- O(1)
func Sort012LL_Brute(ls *ll.LinkedList) {
	cnt0 := 0
	cnt1 := 0
	cnt2 := 0

	for node := ls.Head; node != nil; node = node.Next {
		if node.Data.(int) == 0 {
			cnt0++
		} else if node.Data.(int) == 1 {
			cnt1++
		} else {
			cnt2++
		}
	}

	for node := ls.Head; node != nil; node = node.Next {
		if cnt0 > 0 {
			node.Data = 0
			cnt0--
		} else if cnt1 > 0 {
			node.Data = 1
			cnt1--
		} else if cnt2 > 0 {
			node.Data = 2
			cnt2--
		}
	}
}

// Time :- O(N) Space :- O(1)
func Sort012LL_Optimal(ls *ll.LinkedList) *ll.Node {
	dummy0 := ll.NewNode(nil, nil)
	curr0 := dummy0

	dummy1 := ll.NewNode(nil, nil)
	curr1 := dummy1

	dummy2 := ll.NewNode(nil, nil)
	curr2 := dummy2

	for node := ls.Head; node != nil; node = node.Next {
		if node.Data.(int) == 0 {
			curr0.Next = node
			curr0 = curr0.Next

		} else if node.Data.(int) == 1 {
			curr1.Next = node
			curr1 = curr1.Next

		} else if node.Data.(int) == 2 {
			curr2.Next = node
			curr2 = curr2.Next
		}
	}

	curr0.Next = dummy1.Next
	curr1.Next = dummy2.Next
	curr2.Next = nil

	return dummy0.Next
}
