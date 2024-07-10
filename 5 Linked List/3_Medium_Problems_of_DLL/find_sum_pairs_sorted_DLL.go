package mediumproblemsofdll

import (
	dll "linked_list/1_DS/Doubly_Linked_List"
)

// Time :- O(N*N) Space :- O(1)
func FindSumPairsDLL_Brute(dls *dll.DoubleLinkedList, k int) [][]int {
	ans := make([][]int, 0, dls.Size())

	for i := dls.Head; i != nil; i = i.Next {
		for j := i.Next; j != nil; j = j.Next {
			sum := i.Data.(int) + j.Data.(int)
			if sum == k {
				res := []int{i.Data.(int), j.Data.(int)}
				ans = append(ans, res)
			}
		}
	}

	return ans
}

// Time :- O(N) Space :- O(N)
func FindSumPairsDLL_Hashing(dls *dll.DoubleLinkedList, k int) [][]int {
	ans := make([][]int, 0, dls.Size())
	mpp := make(map[int]*dll.Node)

	for node := dls.Head; node != nil; node = node.Next {
		rem := k - node.Data.(int)

		if _, ok := mpp[rem]; ok {
			ans = append(ans, []int{rem, node.Data.(int)})
		}
		mpp[node.Data.(int)] = node
	}

	return ans
}

// Time :- O(N) Space :- O(1)
func FindSumPairsDLL_Optimal(dls *dll.DoubleLinkedList, k int) [][]int {
	ans := make([][]int, 0, dls.Size())
	left := dls.Head
	right := dls.Tail

	for left.Data.(int) < right.Data.(int) {
		sum := left.Data.(int) + right.Data.(int)

		if sum < k {
			left = left.Next

		} else if sum > k {
			right = right.Prev

		} else {
			ans = append(ans, []int{left.Data.(int), right.Data.(int)})
			left = left.Next
			right = right.Prev
		}
	}

	return ans
}
