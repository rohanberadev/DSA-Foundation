package main

import (
	stronghold "Recursion/1_Strong_Hold"
	ds "Recursion/DS"
)

func main() {
	// Question 1
	// fmt.Println(basics.Factorial(5))

	// Question 2
	// arr := []int{1, 2, 3, 4, 5}
	// fmt.Println(basics.SumOfArray_1(arr, len(arr)-1))
	// fmt.Println(basics.SumOfArray_2(arr))

	// Question 3
	// arr := []int{1, 2, 8, 9, 8, 5, 7, 0}
	// fmt.Println(basics.FindFisrtIndexOfElemArray_1(arr, 8, len(arr), -1))
	// fmt.Println(basics.FindFisrtIndexOfElemArray_2(arr, 8, -1))
	// fmt.Println(basics.FindFisrtIndexOfElemArray_3(arr, 8))

	// Question 4
	// arr := []int{1, 2, 8, 9, 8, 5, 7, 0}
	// fmt.Println(basics.FindLastIndexOfElemArray_1(arr, len(arr), 8))
	// fmt.Println(basics.FindLastIndexOfElemArray_2(arr, 8))

	// Question 5
	// arr := []int{1, 0, 0, 1, 0, 1, 0, 1}
	// fmt.Println(basics.CountZeroesArray_1(arr, len(arr)))
	// fmt.Println(basics.CountZeroesArray_2(arr))

	// Question 6
	// s := "pipipppipi"
	// fmt.Println(basics.ReplacePI_1(s))

	// Question 7
	// s := "geeksforgeeks"
	// fmt.Println(basics.ReplaceOccurences(s, "e"))

	// Question 8
	// s := "   -042"
	// fmt.Println(stronghold.Atoi_Recursive(s))

	// Question 9

	// Question 10
	// fmt.Println(stronghold.Pow_Iterative(2, 9))
	// fmt.Println(stronghold.Pow_Recursive(2, -2))

	// Question 11
	// fmt.Println(stronghold.CountGoodNumbers_Recursive_Brute(50))
	// fmt.Println(stronghold.CountGoodNumbers_Recursive_Optimal(50))

	// Question 12
	// fmt.Println(stronghold.Atoi_Recursive("45"))
	// fmt.Println(stronghold.Atoi_Iterative("1337c0d3"))

	// Question 13
	// st := ds.NewStack()
	// st.Push(3)
	// st.Push(1)
	// st.Push(4)
	// st.Push(2)

	// stronghold.SortStack_Recursive(st)
	// st.Print()

	// Question 14
	st := ds.NewStack()
	st.Push(4)
	st.Push(3)
	st.Push(2)
	st.Push(1)

	// ans := ds.NewStack()

	st.Print()
	// stronghold.ReverseStack_Recursive_Brute(st, ans)
	// ans.Print()

	stronghold.ReverseStack_Recursive_Optimal(st)
	st.Print()
}