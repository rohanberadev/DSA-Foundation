package medium

func Sort0_1_2Counting(arr []int) []int {
	count_0 := 0
	count_1 := 0
	count_2 := 0

	n := len(arr)

	for i := 0; i < n; i++ {
		if arr[i] == 0 {
			count_0++

		} else if arr[i] == 1 {
			count_1++

		} else {
			count_2++
		}
	}

	for i := 0; i < n; i++ {
		if count_0 > 0 {
			arr[i] = 0
			count_0--

		} else if count_1 > 0 {
			arr[i] = 1
			count_1--

		} else {
			arr[i] = 2
			count_2--
		}
	}

	return arr
}

func Sort0_1_2DutchNationalFlag(arr []int) []int {
	n := len(arr)
	low := 0
	mid := 0
	high := n - 1

	for mid <= high {
		if arr[mid] == 0 {
			temp := arr[mid]
			arr[mid] = arr[low]
			arr[low] = temp
			low++
			mid++

		} else if arr[mid] == 2 {
			temp := arr[mid]
			arr[mid] = arr[high]
			arr[high] = temp
			high--

		} else if arr[mid] == 1 {
			mid++
		}

	}

	return arr
}
