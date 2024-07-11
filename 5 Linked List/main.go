package main

import hardproblemsofll "linked_list/4_Hard_Problems_of_LL"

func main() {
	// arr := []interface{}{9, 9, 8}
	// ls := ll.ConvertArrayToLL(arr)

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
	// ll.NewList(mediumproblemsofll.Sort012LL_Optimal(ls)).Print()

	// Question 12
	// head1 := ll.NewNode(1, nil)
	// head1.Next = ll.NewNode(3, nil)
	// head1.Next.Next = ll.NewNode(1, nil)
	// head1.Next.Next.Next = ll.NewNode(2, nil)
	// intersect := head1.Next.Next.Next
	// head1.Next.Next.Next.Next = ll.NewNode(4, nil)

	// head2 := ll.NewNode(3, nil)
	// head2.Next = intersect

	// ls1 := ll.ConvertArrayToLL([]interface{}{1, 2, 7})
	// ls2 := ll.ConvertArrayToLL([]interface{}{2, 8, 1})

	// fmt.Println(mediumproblemsofll.FindIntersection2List_Brute(head1, head2))
	// fmt.Println(mediumproblemsofll.FindIntersection2List_Brute(ls1.Head, ls2.Head))

	// fmt.Println(mediumproblemsofll.FindIntersection2List_Hashing(head1, head2))
	// fmt.Println(mediumproblemsofll.FindIntersection2List_Hashing(ls1.Head, ls2.Head))

	// fmt.Println(mediumproblemsofll.FindIntersection2List_Optimal1(head1, head2))
	// fmt.Println(mediumproblemsofll.FindIntersection2List_Optimal1(ls1.Head, ls2.Head))

	// fmt.Println(mediumproblemsofll.FindIntersection2List_Optimal2(head1, head2))
	// fmt.Println(mediumproblemsofll.FindIntersection2List_Optimal2(ls1.Head, ls2.Head))

	// Question 13
	// mediumproblemsofll.Add1ToLL(ls)
	// ls.Print()

	// Question 14
	// ls1 := ll.ConvertArrayToLL([]interface{}{2, 4, 6, 0, 6})
	// ls2 := ll.ConvertArrayToLL([]interface{}{3, 8, 7})
	// head := mediumproblemsofll.Add2Numbers(ls1, ls2)
	// for node := head; node != nil; node = node.Next {
	// 	fmt.Printf("%v ", node.Data)
	// }
	// fmt.Print("\n")

	// Question 15
	// dls := dll.ConvertArrayToDLL([]interface{}{10, 4, 10, 10, 6, 10})
	// mediumproblemsofdll.DeleteOccurences(dls, 10)
	// dls.Print()

	// Question 16
	// dls := dll.ConvertArrayToDLL([]interface{}{1, 2, 3, 4, 9})
	// fmt.Println(mediumproblemsofdll.FindSumPairsDLL_Brute(dls, 5))
	// fmt.Println(mediumproblemsofdll.FindSumPairsDLL_Hashing(dls, 5))
	// fmt.Println(mediumproblemsofdll.FindSumPairsDLL_Optimal(dls, 5))

	// Question 17
	// dls := dll.ConvertArrayToDLL([]interface{}{1, 2, 2, 4, 4, 5})
	// mediumproblemsofdll.RemoveDuplicatesLL_Hashing(dls)
	// mediumproblemsofdll.RemoveDuplicatesLL_Optimal(dls)
	// dls.Print()

	// Question 18
	// ls := ll.ConvertArrayToLL([]interface{}{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12})
	// hardproblemsofll.ReverseGivenSizeLL(ls, 3)
	// ls.Print()

	// Question 19
	// ls := ll.ConvertArrayToLL([]interface{}{1, 2, 3, 4, 5})
	// hardproblemsofll.RotateLeftLL_Brute(ls, 1)
	// hardproblemsofll.RotateRightLL_Brute(ls, 3)
	// hardproblemsofll.RotateLeftLL_Optimal(ls, 1)
	// hardproblemsofll.RotateRightLL_Optimal(ls, 4)
	// ls.Print()

	// Question 20
	head := hardproblemsofll.NewNodeWithChild(3, nil, nil)
	head.Next = hardproblemsofll.NewNodeWithChild(2, nil, nil)
	head.Next.Child = hardproblemsofll.NewNodeWithChild(10, nil, nil)

	head.Next.Next = hardproblemsofll.NewNodeWithChild(1, nil, nil)
	head.Next.Next.Child = hardproblemsofll.NewNodeWithChild(7, nil, nil)
	head.Next.Next.Child.Child = hardproblemsofll.NewNodeWithChild(11, nil, nil)
	head.Next.Next.Child.Child.Child = hardproblemsofll.NewNodeWithChild(12, nil, nil)

	head.Next.Next.Next = hardproblemsofll.NewNodeWithChild(4, nil, nil)
	head.Next.Next.Next.Child = hardproblemsofll.NewNodeWithChild(9, nil, nil)

	head.Next.Next.Next.Next = hardproblemsofll.NewNodeWithChild(5, nil, nil)
	head.Next.Next.Next.Next.Child = hardproblemsofll.NewNodeWithChild(6, nil, nil)
	head.Next.Next.Next.Next.Child.Child = hardproblemsofll.NewNodeWithChild(8, nil, nil)

	// hardproblemsofll.FlattenLL_Brute(head).Print()
	hardproblemsofll.PrintNodeWithChild(hardproblemsofll.FlattenLL_Optimal(head))
}
