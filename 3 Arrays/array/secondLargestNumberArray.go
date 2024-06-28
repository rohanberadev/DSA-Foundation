package array

import (
	"fmt"
	"math"
)

func FindSecondSmallestAndLargestNumberOptimal(arr []int) {
	firstMax := math.MinInt
	secondMax := math.MinInt

	firstMin := math.MaxInt
	secondMin := math.MaxInt

	n := len(arr)

	for i := 0; i < n; i++ {
		// For Smallest Number
		if firstMin > arr[i] {
			secondMin = firstMin
			firstMin = arr[i]

		} else if secondMin > arr[i] && firstMin < arr[i] {
			secondMin = arr[i]
		}

		// For largest number
		if firstMax < arr[i] {
			secondMax = firstMax
			firstMax = arr[i]

		} else if secondMax < arr[i] && firstMax > arr[i] {
			secondMax = arr[i]
		}
	}

	fmt.Printf("Second Smallest number is %v\n", secondMin)
	fmt.Printf("Second Largest number is %v\n", secondMax)

}

func FindSecondSmallestAndLargestNumberBetter(arr []int) {
	firstMax := arr[0]
	firstMin := arr[0]

	n := len(arr)

	for i := 0; i < n; i++ {
		if firstMax < arr[i] {
			firstMax = arr[i]

		} else if firstMin > arr[i] {
			firstMin = arr[i]
		}
	}

	secondMax := math.MinInt
	secondMin := math.MaxInt

	for i := 0; i < n; i++ {
		if secondMin > arr[i] && firstMin < arr[i] {
			secondMin = arr[i]

		} else if secondMax < arr[i] && firstMax > arr[i] {
			secondMax = arr[i]
		}
	}

	fmt.Printf("Second Smallest number is %v\n", secondMin)
	fmt.Printf("Second Largest number is %v\n", secondMax)

}

func FindSecondSmallestAndLargestNumberSorting(arr []int) {
	n := len(arr)
	MergeSort(&arr, 0, n-1)

	fmt.Printf("Second Smallest number is %v\n", arr[1])
	fmt.Printf("Second Largest number is %v\n", arr[n-2])
}
