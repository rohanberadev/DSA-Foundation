package main

import (
	basics "Recursion/0_Basics"
	"fmt"
	"time"
)

func main() {
	start := time.Now()

	/* Basics */

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
	// basics.PrintNamesNTimes("rohan", 5)

	// Question 9
	// basics.PrintNLinearly(1, 5)
	// basics.PrintNReverse(5)

	// Question 10
	// basics.PrintNLinearly_BackTrack(5)
	// basics.PrintNReverse_BackTrack(5)

	// Question 11
	// basics.SumOfN_Parameterized_1(5, 0)
	// fmt.Println(basics.SumOfN_Parameterized_2(5, 0))
	// fmt.Println(basics.SumOfN_Functional(5))

	// fmt.Println(basics.FactorialOfN(5))

	// Question 12
	// arr := []int{1, 2, 3, 4}
	// basics.ReverseAnArray_Pointer(0, len(arr)-1, arr)
	// basics.ReverseAnArray_Parameterized(arr, 0)
	// fmt.Println(arr)

	// Question 13
	// s := "1221"
	// fmt.Println(basics.CheckPalindrome_Functional_Pointers(s, 0, len(s)-1))
	// fmt.Println(basics.CheckPalindrome_Functional_Parameterized(s, 0))

	// Question 14
	// fmt.Println(basics.Fibonacci_Brute(120))
	fmt.Println(basics.Fibonacci_Optimal(120))

	/* Strong Hold*/

	// Question 1
	// s := "   -042"
	// fmt.Println(stronghold.Atoi_Recursive(s))

	// Question 2
	// fmt.Println(stronghold.Pow_Iterative(2, 9))
	// fmt.Println(stronghold.Pow_Recursive(2, -2))

	// Question 3
	// fmt.Println(stronghold.CountGoodNumbers_Recursive_Brute(50))
	// fmt.Println(stronghold.CountGoodNumbers_Recursive_Optimal(50))

	// Question 4
	// fmt.Println(stronghold.Atoi_Recursive("45"))
	// fmt.Println(stronghold.Atoi_Iterative("1337c0d3"))

	// Question 5
	// st := ds.NewStack()
	// st.Push(3)
	// st.Push(1)
	// st.Push(4)
	// st.Push(2)

	// stronghold.SortStack_Recursive(st)
	// st.Print()

	// Question 6
	// st := ds.NewStack()
	// st.Push(4)
	// st.Push(3)
	// st.Push(2)
	// st.Push(1)

	// ans := ds.NewStack()

	// st.Print()
	// stronghold.ReverseStack_Recursive_Brute(st, ans)
	// ans.Print()

	// stronghold.ReverseStack_Recursive_Optimal(st)
	// st.Print()

	// Question 7
	// subsequencepattern.GenerateBinaryStrings(3)

	// Question 8
	// fmt.Println(subsequencepattern.GenerateParathesis(3))

	elapsed := time.Since(start).Milliseconds()
	fmt.Printf("\nTime taken: %v ms\n", elapsed)
}
