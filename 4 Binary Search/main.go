package main

import (
	"fmt"
	arrayans "myBinarySearch/arrayAns"
)

func main() {
	arr := []int{12, 34, 67, 90}

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

	fmt.Println(arrayans.AllocateMinNumOfPages_MySelf(arr, 2))
	fmt.Println(arrayans.AllocateMinNumOfPages_Brute(arr, 2))
	fmt.Println(arrayans.AllocateMinNumOfPages_Optimal(arr, 2))
}
