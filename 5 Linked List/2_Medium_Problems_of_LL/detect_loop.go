package mediumproblemsofll

import ll "linked_list/1_DS/Singly_Linked_List"

// Time :- O(N) Space :- O(N)
func DetectLoop_Brute(ls *ll.LinkedList) bool {
	mpp := make(map[*ll.Node]bool)

	for node := ls.Head; node != nil; node = node.Next {
		if mpp[node] {
			return true
		}

		mpp[node] = true
	}

	return false
}

// Time :- O(N) Space :- O(1)
func DetectLoop_Optimal(ls *ll.LinkedList) bool {
	slow := ls.Head
	fast := ls.Head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next

		if fast == slow {
			return true
		}
	}

	return false
}
