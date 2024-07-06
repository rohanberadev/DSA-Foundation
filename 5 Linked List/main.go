package main

import (
	"fmt"
	ll "linked_list/1_DS/Singly_Linked_List"
	mediumproblemsofll "linked_list/2_Medium_Problems_of_LL"
)

func main() {
	arr := []interface{}{2, 4, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}
	ls := ll.ConvertArrayToLL(arr)

	// Question 1
	fmt.Println(mediumproblemsofll.FindMiddleLL_Brute(ls))
	fmt.Println(mediumproblemsofll.FindMiddleLL_Optimal(ls))
}
