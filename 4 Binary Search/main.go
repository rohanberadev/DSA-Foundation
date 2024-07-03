package main

import (
	"fmt"
	array2d "myBinarySearch/array2D"
)

func main() {
	// arr := []int{1, 13, 17, 23}

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
	// fmt.Println(array1d.FindMinRotatedArrayBrute(arr))
	// fmt.Println(array1d.FindMinRotatedArrayOptimal(arr))

	// Question 11
	// fmt.Println(array1d.FindManyTimesArrayRotatedBrute(arr))
	// fmt.Println(array1d.FindManyTimesArrayRotatedOptimal(arr))

	// Question 12
	// fmt.Println(array1d.FindElemAppearOnceSortedArrayBrute(arr))
	// fmt.Println(array1d.FindElemAppearOnceSortedArrayHashing(arr))
	// fmt.Println(array1d.FindElemAppearOnceSortedArrayXOR(arr))
	// fmt.Println(array1d.FindElemAppearOnceSortedArrayOptimal(arr))

	// Question 13
	// fmt.Println(array1d.FindPeakElementBrute(arr))
	// fmt.Println(array1d.FindPeakElementOptimal(arr))

	// Question 14
	// fmt.Println(arrayans.FindSqrtOfNBrute(28))
	// fmt.Println(arrayans.FindSqrtOfNOptimal(28))

	// Question 15
	// fmt.Println(arrayans.FindNthSqrtOfM_Brute(69, 4))
	// fmt.Println(arrayans.FindNthSqrtOfM_Optimal(27, 3))

	// Question 16
	// fmt.Println(arrayans.KokoBananasBrute(arr, 8))
	// fmt.Println(arrayans.KokoBananasOptimal(arr, 8))

	// Question 17
	// fmt.Println(arrayans.MinDaysToMakeMBouquet_Myself(arr, 3, 2))
	// fmt.Println(arrayans.MinDaysToMakeMBouquet_Brute(arr, 3, 2))
	// fmt.Println(arrayans.MinDaysToMakeMBouquet_Optimal(arr, 3, 2))

	// Question 18
	// fmt.Println(arrayans.FindSmallestDivisorBrute(arr, 8))
	// fmt.Println(arrayans.FindSmallestDivisorOptimal(arr, 8))

	// Question 19
	// fmt.Println(arrayans.FindLowestCapacityShipPackagesWithinDays_Brute(arr, 5))
	// fmt.Println(arrayans.FindLowestCapacityShipPackagesWithinDays_Optimal(arr, 5))

	// Question 20
	// fmt.Println(arrayans.FindKthMissingNum_Brute(arr, 4))
	// fmt.Println(arrayans.FindKthMissingNum_Optimal(arr, 4))

	// Question 21
	// fmt.Println(arrayans.AgressiveCows_Brute(arr, 4))
	// fmt.Println(arrayans.AgressiveCows_Optimal(arr, 4))

	// Question 22
	// fmt.Println(arrayans.AllocateMinNumOfPages_Brute(arr, 2))
	// fmt.Println(arrayans.AllocateMinNumOfPages_Optimal(arr, 2))

	// Question 23
	// fmt.Println(arrayans.SplitArrayLargestSum_Brute(arr, 3))
	// fmt.Println(arrayans.SplitArrayLargestSum_Optimal(arr, 3))

	// Question 24
	// fmt.Println(arrayans.PainterPartition_Brute(arr, 2))
	// fmt.Println(arrayans.PainterPartition_Optimal(arr, 2))

	// Question 25
	// fmt.Println(arrayans.MinimizeMaxDistGasStations_Brute(arr, 4))
	// fmt.Println(arrayans.MinimizeMaxDistGasStations_PriorityQueue(arr, 4))
	// fmt.Println(arrayans.MinimizeMaxDistGasStations_Optimal(arr, 4))

	// Question 26
	// arr1 := []int{2, 4, 6}
	// arr2 := []int{1, 3, 5}
	// fmt.Println(arrayans.MedianOf2SortedArray_Brute(arr1, arr2))
	// fmt.Println(arrayans.MedianOf2SortedArray_Better(arr1, arr2))
	// fmt.Println(arrayans.MedianOf2SortedArray_Optimal(arr1, arr2))

	// Question 27
	// arr1 := []int{2, 4, 6}
	// arr2 := []int{1, 3, 5}
	// fmt.Println(arrayans.KthElementOf2SortedArray_Brute(arr1, arr2, 4))
	// fmt.Println(arrayans.KthElementOf2SortedArray_Better(arr1, arr2, 4))
	// fmt.Println(arrayans.KthElementOf2SortedArray_Optimal(arr1, arr2, 1))

	// Question 28
	// mat := [][]int{{1, 1, 1}, {0, 0, 1}, {0, 0, 0}}
	// fmt.Println(array2d.FindMaxNumberOf1InRow_Brute(mat))
	// fmt.Println(array2d.FindMaxNumberOf1InRow_Optimal(mat))

	// Question 29
	// mat := [][]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}
	// fmt.Println(array2d.SearchIn2DArray_Brute(mat, 8))
	// fmt.Println(array2d.SearchIn2DArray_Better(mat, 8))
	// fmt.Println(array2d.SearchIn2DArray_Optimal(mat, 8))

	// Question 30
	mat := [][]int{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}}

	fmt.Println(array2d.SearchIn2DArrayRowAndColWise_Brute(mat, 8))
	fmt.Println(array2d.SearchIn2DArrayRowAndColWise_Better(mat, 8))
	fmt.Println(array2d.SearchIn2DArrayRowAndColWise_Optimal(mat, 8))
}
