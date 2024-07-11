package hardproblemsofll

import (
	ll "linked_list/1_DS/Singly_Linked_List"
)

func RotateLeftLL_Brute(ls *ll.LinkedList, k int) {
	if ls.Head == nil || ls.Head.Next == nil || k == 0 {
		return
	}

	for i := 1; i <= k; i++ {
		temp := ls.Head
		newHead := temp.Next
		temp.Next = nil
		ls.Tail.Next = temp
		ls.Tail = temp
		ls.Head = newHead
	}
}

// IMP
func RotateRightLL_Brute(ls *ll.LinkedList, k int) {
	if ls.Head == nil || ls.Head.Next == nil || k == 0 {
		return
	}

	for i := 1; i <= k; i++ {
		temp := ls.Head
		for temp.Next.Next != nil {
			temp = temp.Next
		}
		ls.Tail = temp
		end := temp.Next
		end.Next = ls.Head
		ls.Head = end
		temp.Next = nil
	}

}

func RotateLeftLL_Optimal(ls *ll.LinkedList, k int) {
	n := ls.Size()
	k = k % n

	if ls.Head == nil || ls.Head.Next == nil || k == 0 {
		return
	}

	temp := ls.Head

	for i := 1; i < k; i++ {
		if temp != nil {
			temp = temp.Next
		}
	}

	end := temp
	head := temp.Next

	for temp.Next != nil {
		temp = temp.Next
	}

	temp.Next = ls.Head
	ls.Head = head
	ls.Tail = end
	end.Next = nil
}

// IMP
func RotateRightLL_Optimal(ls *ll.LinkedList, k int) {
	n := ls.Size()
	k = k % n

	if ls.Head == nil || ls.Head.Next == nil || k == 0 {
		return
	}

	cnt := n - k - 1
	temp := ls.Head

	for cnt > 0 {
		temp = temp.Next
		cnt--
	}

	head := temp.Next
	end := temp

	for temp.Next != nil {
		temp = temp.Next
	}

	temp.Next = ls.Head
	ls.Head = head
	ls.Tail = end
	end.Next = nil
}
