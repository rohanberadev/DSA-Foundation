package hardproblemsofll

// Time :- O(N1 + N2)
func Merge2List(ls1, ls2 *NodeWithChild) *NodeWithChild {
	dummy := NewNodeWithChild(nil, nil, nil)
	temp := dummy

	for ls1 != nil && ls2 != nil {
		if ls1.Data.(int) <= ls2.Data.(int) {
			temp.Child = ls1
			ls1 = ls1.Child

		} else {
			temp.Child = ls2
			ls2 = ls2.Child
		}
		temp = temp.Child
		temp.Next = nil
	}

	if ls1 != nil {
		temp.Child = ls1
	} else {
		temp.Child = ls2
	}

	if dummy.Child != nil {
		dummy.Child.Next = nil
	}

	return dummy.Child
}

func FlattenLL_Optimal(head *NodeWithChild) *NodeWithChild {
	if head == nil || head.Next == nil {
		return head
	}

	mergedHead := FlattenLL_Optimal(head.Next)
	head = Merge2List(head, mergedHead)

	return head
}
