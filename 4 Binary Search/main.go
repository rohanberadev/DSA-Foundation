package main

import (
	"fmt"
	array1d "myBinarySearch/array1D"
)

func main() {
	arr := []int{4, 5, 6, 7, 0, 1, 2, 3}

	// Question 1
	// fmt.Println(array1d.BinarySearchIterative(arr, 6))
	// fmt.Println(array1d.BinarySearchRecursive(arr, 0, len(arr)-1, 6))

	// Question 2
	// fmt.Println(array1d.LowerBoundBrute(arr, 9))
	// fmt.Println(array1d.LowerBoundOptimal(arr, 9))

	// Question 3
	// fmt.Println(array1d.HigherBoundBrute(arr, 9))
	// fmt.Println(array1d.HigherBoundOptimal(arr, 9))

	// Question 4
	// fmt.Println(array1d.SearchInsertPos(arr, 6))

	// Question 5
	// fmt.Println(array1d.FindFloor(arr, 8))
	// fmt.Println(array1d.FindCeil(arr, 8))

	// Question 6
	// fmt.Println(array1d.LastOcurrenceBrute(arr, 13))
	// fmt.Println(array1d.LastOcurrenceBrute(arr, 13))

	// Question 7
	// fmt.Println(array1d.CountOccurenceBrute(arr, 3))
	// fmt.Println(array1d.CountOccurenceOptimal(arr, 3))

	// Question 8
	// fmt.Println(array1d.SearchRotatedArray1Brute(arr, 1))
	// fmt.Println(array1d.SearchRotatedArray1Optimal(arr, 1))

	// Question 9
	// fmt.Println(array1d.SearchRotatedArray2Brute(arr, 3))
	// fmt.Println(array1d.SearchRotatedArray2Optimal(arr, 3))

	// Question 10
	fmt.Println(array1d.FindMinRotatedArrayBrute(arr))
	fmt.Println(array1d.FindMinRotatedArrayOptimal(arr))
}
