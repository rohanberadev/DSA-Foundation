package main

import (
	"fmt"
	ll "linked_list/1_DS/Singly_Linked_List"
	mediumproblemsofll "linked_list/2_Medium_Problems_of_LL"
)

func main() {
	arr := []interface{}{1, 2, 3, 2, 1}
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
	fmt.Println(mediumproblemsofll.IsListPalindrome_Brute(ls))
	fmt.Println(mediumproblemsofll.IsListPalindrome_Optimal(ls))
	ls.Print()
}
