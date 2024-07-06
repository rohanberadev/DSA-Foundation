package mediumproblemsofll

import ll "linked_list/1_DS/Singly_Linked_List"

// Time :- O(N + N/2)
func FindMiddleLL_Brute(ls *ll.LinkedList) *ll.Node {
	// Time :- O(N)
	mid := ls.Size()/2 + 1

	mover := ls.Head
	cnt := 1
	// Time :- O(N/2)
	for cnt < mid {
		cnt++
		mover = mover.Next
	}

	return mover
}

// Time :- O(N/2)
func FindMiddleLL_Optimal(ls *ll.LinkedList) *ll.Node {
	slow := ls.Head
	fast := ls.Head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	return slow
}
