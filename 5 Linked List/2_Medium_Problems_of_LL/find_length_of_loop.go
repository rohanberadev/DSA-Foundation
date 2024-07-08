package mediumproblemsofll

import ll "linked_list/1_DS/Singly_Linked_List"

// Time :- O(N) Space :- O(N)
func FindLengthOfLoop_Brute(ls *ll.LinkedList) int {
	mpp := make(map[*ll.Node]int)
	cnt := 0

	for node := ls.Head; node != nil; node = node.Next {
		if val, ok := mpp[node]; ok {
			return cnt - val
		}
		mpp[node] = cnt
		cnt++
	}

	return 0
}

func FindLengthOfLoop_Optimal(ls *ll.LinkedList) int {
	slow := ls.Head
	fast := ls.Head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next

		if slow == fast {
			// Counting Length.
			cnt := 0
			temp := fast
			slow = ls.Head

			for slow != fast {
				slow = slow.Next
				fast = fast.Next
				cnt++
			}

			for slow != temp {
				slow = slow.Next
				cnt++
			}

			return cnt
		}
	}

	return 0
}
