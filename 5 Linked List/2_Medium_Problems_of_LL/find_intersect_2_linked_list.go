package mediumproblemsofll

import ll "linked_list/1_DS/Singly_Linked_List"

// Time :- O(N * M) Space :- O(1)
func FindIntersection2List_Brute(head1, head2 *ll.Node) *ll.Node {
	for node1 := head1; node1 != nil; node1 = node1.Next {
		for node2 := head2; node2 != nil; node2 = node2.Next {
			if node1 == node2 {
				return node1
			}
		}
	}

	return nil
}

// Time :- O(N + M) Space :- O(N)
func FindIntersection2List_Hashing(head1, head2 *ll.Node) *ll.Node {
	mpp := make(map[*ll.Node]bool)

	for node := head1; node != nil; node = node.Next {
		mpp[node] = true
	}

	for node := head2; node != nil; node = node.Next {
		if mpp[node] {
			return node
		}
	}

	return nil
}

func getDifferenceOfLen(head1, head2 *ll.Node) int {
	node1 := head1
	node2 := head2

	l1 := 1
	l2 := 1

	for node1 != nil || node2 != nil {
		if node1 != nil {
			node1 = node1.Next
			l1++
		}
		if node2 != nil {
			node2 = node2.Next
			l2++
		}
	}

	return l1 - l2
}

// Time :- O((N+M) + (max(N, M)-min(N, M)) + min(N, M)) Space :- O(1)
func FindIntersection2List_Optimal1(head1, head2 *ll.Node) *ll.Node {
	diff := getDifferenceOfLen(head1, head2)
	node1 := head1
	node2 := head2

	if diff < 0 {
		// head2 is greater.
		for diff < 0 {
			node2 = node2.Next
			diff++
		}
	} else {
		// head1 is greater.
		for diff > 0 {
			node1 = node1.Next
			diff--
		}
	}

	for node1 != nil && node2 != nil {
		if node1 == node2 {
			return node1
		}
		node1 = node1.Next
		node2 = node2.Next
	}

	return nil
}

// Time :- O(2 * max(N, M)) Space :- O(1)
func FindIntersection2List_Optimal2(head1, head2 *ll.Node) *ll.Node {
	node1 := head1
	node2 := head2

	for node1 != node2 {
		if node1 == nil {
			node1 = head2
		} else {
			node1 = node1.Next
		}

		if node2 == nil {
			node2 = head1
		} else {
			node2 = node2.Next
		}
	}

	return node1
}
