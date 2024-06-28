package main

import (
	"fmt"
	"myArray/hard"
)

func main() {
	arr := []int{1, 2, -2, 4, -4}
	fmt.Println("Arrays")

	// Question 1
	// fmt.Println(array.FindLargestNumber(arr))
	// fmt.Println(array.FindLargestNumberRecursive(arr, len(arr)-1, 0))
	// fmt.Println(array.FindLargestNumberSorting(arr))

	// Question 2
	// array.FindSecondSmallestAndLargestNumberSorting(arr)
	// array.FindSecondSmallestAndLargestNumberBetter(arr)
	// array.FindSecondSmallestAndLargestNumberOptimal(arr)

	// Question 3
	// fmt.Println(array.CheckArraySorted(arr))
	// fmt.Println(array.CheckArraySortedOptimal(arr))
	// fmt.Println(array.CheckArraySortedTwoPointer(arr))

	// Question 4
	// array.RemoveDuplicatesSortedArray(arr)

	// Question 5
	// array.PrintArray(array.LeftRotateArrayByOne(arr))
	// array.PrintArray(array.LeftRotateArrayByOneOptimal(arr))

	// Question 6
	// array.PrintArray(array.LeftRotataArray(arr, 6))
	// array.PrintArray(array.RightRotateArray(arr, 2))

	// Question 7
	// array.PrintArray(array.MoveAllZeroesToEndBrute(arr))
	// array.PrintArray(array.MoveAllZeroesToEndOptimal1(arr))
	// array.PrintArray(array.MoveAllZeroesToEndOptimal2(arr))

	// Question 8
	// fmt.Println(array.LinearSearch(arr, 1))

	// Question 9
	// arr1 := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	// arr2 := []int{2, 3, 4, 4, 5, 11, 12}
	// array.PrintArray(array.FindUnionSortedArrayUsingMap(arr1, arr2))
	// array.PrintArray(array.FindUnionSortedArrayUsingPointers(arr1, arr2))

	// Question 10
	// println(array.FindMissingNumberBetterHashing(arr))
	// println(array.FindMissingNumberOptimalSummation(arr))
	// println(array.FindMissingNumberOptimalXOR(arr))

	// Question 11
	// println(array.CountMaxConsecutiveOnes(arr))

	// Question 12
	// println(array.FindNumAppearOnceOthersTwiceBrute(arr))
	// println(array.FindNumAppearOnceOthersTwiceHashing(arr))
	// println(array.FindNumAppearOnceOthersTwiceOptimalXor(arr))

	// Question 13
	// fmt.Println(array.FindLongestSubArrayGivenNumBrute(arr, 10))
	// fmt.Println(array.FindLongestSubArrayGivenNum(arr, 10))
	// fmt.Println(array.FindLongestSubArrayGivenNumHashing(arr, 10))
	// fmt.Println(array.FindLongestSubArrayGivenNumTwoPointer(arr, 10))

	// Question 14
	// fmt.Println(array.FindLongestSubArrayPosNegGivenNumBrute(arr, 1))
	// fmt.Println(array.FindLongestSubArrayPosNegGivenNumBetter(arr, 1))
	// fmt.Println(array.FindLongestSubArrayPosNegGivenNumHashing(arr, 1))

	// Question 15
	// fmt.Println(medium.FindPairGivenSumBrute(arr, 14))
	// fmt.Println(medium.FindPairGivenSumHashing(arr, 14))
	// fmt.Println(medium.FindPairGivenSumSorted(arr, 14))

	// Question 16
	// array.PrintArray(medium.Sort0_1_2Counting(arr))
	// array.PrintArray(medium.Sort0_1_2DutchNationalFlag(arr))

	// Question 17
	// fmt.Println(medium.OccurmajorityBrute(arr))
	// fmt.Println(medium.OccurMajorityHashing(arr))
	// fmt.Println(medium.OccurMajorityMooresVoting(arr))

	// Question 18
	// fmt.Println(medium.MaximumSubarraySumBrute(arr))
	// fmt.Println(medium.MaximumSubarraySumBetter(arr))
	// fmt.Println(medium.MaximumSubarraySumKandane(arr))

	// Question 19
	// medium.PrintMaximumSumSubArrayBrute(arr)
	// medium.PrintMaximumSumSubArrayBetter(arr)
	// medium.PrintMaximumSumSubArrayBetter(arr)

	// Question 20
	// fmt.Println(medium.Buy_SellStockBrute(arr))
	// fmt.Println(medium.Buy_SellStockOptimal(arr))

	// Question 21
	// array.PrintArray(medium.RearrangeBySignBrute(arr))
	// array.PrintArray(medium.RearrangeBySignOptimal(arr))
	// array.PrintArray(medium.RearrangeBySignVariety2(arr))

	// Question 22
	// ans := list.New()
	// medium.Permutation(arr, list.New(), ans, make([]bool, len(arr)))
	// for e := ans.Front(); e != nil; e = e.Next() {
	// 	a := e.Value.(*list.List)
	// 	for i := a.Front(); i != nil; i = i.Next() {
	// 		fmt.Printf("%v ", i.Value)
	// 	}
	// 	fmt.Print("\n")
	// }

	// fmt.Println(medium.NextPermutationOptimal(arr))
	// fmt.Println(medium.NextPermutationBrute(arr))

	// Question 23
	// medium.LeaderArrayBrute(arr)
	// array.PrintArray(medium.LeaderArrayOptimal(arr))

	// Question 24
	// fmt.Println(medium.MaximumConsecutiveNumBrute(arr))
	// fmt.Println(medium.MaximumConsecutiveNumBetter(arr))
	// fmt.Println(medium.MaximumConsecutiveNumOptimal(arr))

	// Question 25
	// matrix := [][]int{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}
	// medium.PrintMatrix(matrix, 3, 3)
	// medium.PrintMatrix(medium.SetMatrixZeroBrute(matrix, 3, 3), 3, 3)
	// medium.PrintMatrix(medium.SetMatrixZeroBetter(matrix, 3, 3), 3, 3)
	// medium.PrintMatrix(medium.SetMatrixZeroOptimal(matrix, 3, 3), 3, 3)

	// Question 26
	// matrix := [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
	// medium.PrintMatrix(matrix, 3, 3)
	// medium.PrintMatrix(medium.RotateMatrix90DegreeBrute(matrix, 3), 3, 3)
	// medium.PrintMatrix(medium.TransposeBrute(matrix, 3, 3), 3, 3)
	// medium.PrintMatrix(medium.TransposeOptimal(matrix, 3), 3, 3)
	// medium.PrintMatrix(medium.RotateMatrix90DegreeOptimal(matrix, 3), 3, 3)

	// Question 27
	// matrix := [][]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}
	// medium.PrintMatrix(matrix, 4, 4)
	// fmt.Println(medium.SpiralMatrix(matrix))

	// Question 28
	// fmt.Println(medium.CountSubArraysBrute(arr, 6))
	// fmt.Println(medium.CountSubArraysHashing(arr, 6))
	// fmt.Println(medium.CountSubArraysOptimal(arr, 6))

	// Question 29
	// fmt.Println(hard.PascalTriangleVariety1(5, 3))
	// hard.PascalTriangleVariety2(4)
	// hard.PascalTriangleVariety3(5)

	// Question 30
	// fmt.Println(hard.MajorityNDivides3Brute(arr))
	// fmt.Println(hard.MajorityNDivides3Hashing(arr))

	// Question 31
	// fmt.Println(hard.ThreeSumMySelf(arr))
	// fmt.Println(hard.ThreeSumBrute(arr))
	// fmt.Println(hard.ThreeSumBetter(arr))
	// fmt.Println(hard.ThreeSumOptimal(arr))

	// Question 32
	// fmt.Println(hard.FourSumBrute(arr, 9))
	// fmt.Println(hard.FourSumBetter(arr, 9))
	// fmt.Println(hard.FourSumOptimal(arr, 9))

	// Question 33
	// fmt.Println(hard.LengthLongestSubArrayWithSum0Brute(arr))
	// fmt.Println(hard.LengthLongestSubArrayWithSum0Better(arr))
	fmt.Println(hard.LengthLongestSubArrayWithSum0Hashing(arr))

	// Question 34
	// fmt.Println(hard.CountNumSubArrayWithXorKBrute(arr, 6))
	// fmt.Println(hard.CountNumSubArrayWithXorKBetter(arr, 6))
	// fmt.Println(hard.CountNumSubArrayWithXorKHashing(arr, 6))

	// Question 35
	// fmt.Println(hard.MergeOverlappingSubIntervalBrute(arr))
	// fmt.Println(hard.MergeOverlappingSubIntervalOptimal(arr))

	// Question 36
	// arr1 := []int{1, 4, 8, 10}
	// arr2 := []int{2, 3, 9}
	// hard.Merge2SortedArrayWithoutExtraSpaceMySelf(arr1, arr2)
	// hard.Merge2SortedArrayWithoutExtraSpaceOptimal1(arr1, arr2)
	// hard.Merge2SortedArrayWithoutExtraSpaceOptimal2(arr1, arr2)

	// Question 37
	// fmt.Println(hard.FindRepeatAndMissingNumBrute(arr))
	// fmt.Println(hard.FindRepeatAndMissingNumHashing(arr))
	// fmt.Println(hard.FindRepeatAndMissingNumOptimal1(arr))

	// Question 38
	// testCases := [][]int{
	// 	{1, 2, 3, 4, 5},          // No inversions
	// 	{5, 4, 3, 2, 1},          // Maximum inversions
	// 	{1, 1, 1, 1, 1},          // No inversions
	// 	{2, 4, 1, 3, 5},          // Mixed
	// 	{1, 3, 2, 3, 1},          // Some duplicates
	// 	{1},                      // Single element
	// 	{},                       // Empty array
	// 	{10, 20, 30, 5, 7, 8, 1}, // Large random array
	// }

	// fmt.Println(hard.CountInversionBrute(arr))
	// for _, arr := range testCases {
	// 	copyArr := make([]int, len(arr))
	// 	copy(copyArr, arr)
	// 	fmt.Printf("Array: %v, Number of inversions are: %d\n", arr, hard.CountInversionOptimal(copyArr))
	// }

	// Question 39
	// testCases := [][]int{
	// 	{1, 3, 2, 3, 1},        // Expected Output: 2
	// 	{2, 2, 2, 2, 2},        // Expected Output: 0
	// 	{1, 2, 3, 4, 5},        // Expected Output: 0
	// 	{5, 4, 3, 2, 1},        // Expected Output: 4
	// 	{10, 3, 8, 2, 7, 5, 1}, // Expected Output: 8
	// 	{6, 5, 4, 3, 2, 1},     // Expected Output: 6
	// 	{1, 2, 2, 3, 5},        // Expected Output: 2
	// 	{1},                    // Expected Output: 0
	// 	{},                     // Expected Output: 0
	// }

	// // Run test cases and print results
	// for _, arr := range testCases {
	// 	copyArr := make([]int, len(arr))
	// 	copy(copyArr, arr)
	// 	fmt.Printf("Input: %v, Expected Output: %v\n", arr, hard.ReversePairsBrute(copyArr))
	// 	// Calculate reverse pairs count here and print the result
	// }

	// fmt.Println()

	// for _, arr := range testCases {
	// 	copyArr := make([]int, len(arr))
	// 	copy(copyArr, arr)
	// 	fmt.Printf("Input: %v, Expected Output: %v\n", arr, hard.ReversePairsOptimal(copyArr))
	// 	// Calculate reverse pairs count here and print the result
	// }

	// Question 40
	// testCases := [][]int{
	// 	{1, 3, 2, 3, 1},
	// 	{1, 2, 3, 4, 5, 0},
	// 	{1, 2, -3, 4, 5, 0},
	// }

	// for _, arr := range testCases {
	// 	copyArr := make([]int, len(arr))
	// 	copy(copyArr, arr)
	// 	fmt.Printf("%v Expected Output: %v\n", arr, hard.MaxProductSubarrayBrute(copyArr))
	// }

	// for _, arr := range testCases {
	// 	copyArr := make([]int, len(arr))
	// 	copy(copyArr, arr)
	// 	fmt.Printf("%v Expected Output: %v\n", arr, hard.MaxProductSubarrayBetter(copyArr))
	// }

	// for _, arr := range testCases {
	// 	copyArr := make([]int, len(arr))
	// 	copy(copyArr, arr)
	// 	fmt.Printf("%v Expected Output: %v\n", arr, hard.MaxProductSubarrayOptimal1(copyArr))
	// }

	// for _, arr := range testCases {
	// 	copyArr := make([]int, len(arr))
	// 	copy(copyArr, arr)
	// 	fmt.Printf("%v Expected Output: %v\n", arr, hard.MaxProductSubarrayOptimal2(copyArr))
	// }
}
