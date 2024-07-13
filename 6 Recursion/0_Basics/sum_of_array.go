package basics

func SumOfArray_1(arr []int, lastInd int) int {
	if lastInd == 0 {
		return arr[lastInd]
	}

	return arr[lastInd] + SumOfArray_1(arr, lastInd-1)
}

func SumOfArray_2(arr []int) int {
	if len(arr) == 1 {
		return arr[0]
	}

	return arr[len(arr)-1] + SumOfArray_2(arr[0:len(arr)-1])
}
