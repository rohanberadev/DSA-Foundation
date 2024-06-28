package array

func LeftRotateArrayByOne(arr []int) []int {
	n := len(arr)
	temp := make([]int, n)

	for i := 1; i < n; i++ {
		temp[i-1] = arr[i]
	}

	temp[n-1] = arr[0]

	return temp
}

func LeftRotateArrayByOneOptimal(arr []int) []int {
	n := len(arr)
	temp := arr[0]

	for i := 1; i < n; i++ {
		arr[i-1] = arr[i]
	}

	arr[n-1] = temp

	return arr
}
