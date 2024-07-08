package mediumproblemsofll

import ll "linked_list/1_DS/Singly_Linked_List"

// Time :- O(N) Space :- O(N)
func FindStartPointOfLoop_Brute(ls *ll.LinkedList) *ll.Node {
	mpp := make(map[*ll.Node]bool)

	for node := ls.Head; node != nil; node = node.Next {
		if mpp[node] {
			return node
		}

		mpp[node] = true
	}

	return nil
}

// Time :- O(N) Space :- O(1)
func FindStartPointOfLoop_Optimal(ls *ll.LinkedList) *ll.Node {
	slow := ls.Head
	fast := ls.Head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next

		if fast == slow {
			slow = ls.Head

			for slow != fast {
				slow = slow.Next
				fast = fast.Next
			}

			return slow
		}
	}

	return nil
}
