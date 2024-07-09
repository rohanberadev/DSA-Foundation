package main

import (
	ll "linked_list/1_DS/Singly_Linked_List"
	mediumproblemsofll "linked_list/2_Medium_Problems_of_LL"
)

func main() {
	arr := []interface{}{1, 0, 1, 2, 0, 2, 1}
	ls := ll.ConvertArrayToLL(arr)

	// Question 1
	// fmt.Println(mediumproblemsofll.FindMiddleLL_Brute(ls))
	// fmt.Println(mediumproblemsofll.FindMiddleLL_Optimal(ls))

	// Question 2
	// mediumproblemsofll.ReverseLinkedList_Brute(ls)
	// ls.Print()
	// mediumproblemsofll.FindMiddleLL_Optimal(ls)
	// ls.Print()
	// mediumproblemsofll.ReverseLinkedList_Recursive(ls)
	// ls.Print()

	// Question 3
	// loopLs := ll.NewEmptyList()
	// loopLs.Head = ll.NewNode(1, nil)
	// head := loopLs.Head

	// head.Next = ll.NewNode(2, nil)
	// head.Next.Next = ll.NewNode(3, nil)
	// head.Next.Next.Next = ll.NewNode(4, nil)
	// head.Next.Next.Next.Next = ll.NewNode(5, nil)
	// loop := head.Next.Next.Next.Next
	// loop.Next = head.Next.Next

	// fmt.Println(mediumproblemsofll.DetectLoop_Brute(ls))
	// fmt.Println(mediumproblemsofll.DetectLoop_Brute(loopLs))

	// fmt.Println(mediumproblemsofll.DetectLoop_Optimal(ls))
	// fmt.Println(mediumproblemsofll.DetectLoop_Optimal(loopLs))

	// Question 4
	// loopLs := ll.NewEmptyList()
	// loopLs.Head = ll.NewNode(1, nil)
	// head := loopLs.Head

	// head.Next = ll.NewNode(2, nil)
	// head.Next.Next = ll.NewNode(3, nil)
	// head.Next.Next.Next = ll.NewNode(4, nil)
	// head.Next.Next.Next.Next = ll.NewNode(5, nil)
	// loop := head.Next.Next.Next.Next
	// loop.Next = head.Next.Next

	// fmt.Println(mediumproblemsofll.FindStartPointOfLoop_Brute(ls))
	// fmt.Println(mediumproblemsofll.FindStartPointOfLoop_Brute(loopLs))

	// fmt.Println(mediumproblemsofll.FindStartPointOfLoop_Optimal(ls))
	// fmt.Println(mediumproblemsofll.FindStartPointOfLoop_Optimal(loopLs))

	// Question 5
	// loopLs := ll.NewEmptyList()
	// loopLs.Head = ll.NewNode(1, nil)
	// head := loopLs.Head

	// head.Next = ll.NewNode(2, nil)
	// head.Next.Next = ll.NewNode(3, nil)
	// head.Next.Next.Next = ll.NewNode(4, nil)
	// head.Next.Next.Next.Next = ll.NewNode(5, nil)
	// loop := head.Next.Next.Next.Next
	// loop.Next = head.Next.Next

	// fmt.Println(mediumproblemsofll.FindLengthOfLoop_Brute(ls))
	// fmt.Println(mediumproblemsofll.FindLengthOfLoop_Brute(loopLs))

	// fmt.Println(mediumproblemsofll.FindLengthOfLoop_Optimal(ls))
	// fmt.Println(mediumproblemsofll.FindLengthOfLoop_Optimal(loopLs))

	// Question 6
	// fmt.Println(mediumproblemsofll.IsListPalindrome_Brute(ls))
	// fmt.Println(mediumproblemsofll.IsListPalindrome_Optimal(ls))
	// ls.Print()

	// Question 7
	// mediumproblemsofll.SegregateEvenAndOdd_Brute(ls)
	// head := mediumproblemsofll.SegregateEvenAndOdd_Optimal(ls)
	// ll.NewList(head).Print()

	// Question 8
	// fmt.Println(mediumproblemsofll.RemoveNthNodeFromEnd_Brute(ls, 2))
	// fmt.Println(mediumproblemsofll.RemoveNthNodeFromEnd_Optimal(ls, 5))
	// ls.Print()

	// Question 9
	// fmt.Println(mediumproblemsofll.RemoveMiddleElement_Brute(ls))
	// fmt.Println(mediumproblemsofll.RemoveMiddleElement_Optimal(ls))
	// ls.Print()

	// Question 10
	// mediumproblemsofll.MergeSortLL_Brute(ls)
	// mediumproblemsofll.QuickSortLL_Brute(ls)
	// mediumproblemsofll.MergeSortLL_Optimal(ls)
	// ls.Print()

	// Question 11
	// mediumproblemsofll.Sort012LL_Brute(ls)
	// ls.Print()
	ll.NewList(mediumproblemsofll.Sort012LL_Optimal(ls)).Print()

}
