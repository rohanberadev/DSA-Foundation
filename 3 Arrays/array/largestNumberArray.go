package array

func FindLargestNumber(arr []int) int {
	max := arr[0]

	for i := 0; i < len(arr); i++ {
		if max < arr[i] {
			max = arr[i]
		}
	}

	return max
}

// Using bubble sort technique but running it only for once to find the largest number.
func FindLargestNumberSorting(arr []int) int {
	n := len(arr)

	for j := 0; j < n-1; j++ {
		if arr[j] > arr[j+1] {
			temp := arr[j]
			arr[j] = arr[j+1]
			arr[j+1] = temp
		}
	}

	return arr[n-1]
}

func FindLargestNumberRecursive(arr []int, n, max int) int {

	if n < 0 {
		return max
	}

	if arr[n] > max {
		max = arr[n]
	}

	return FindLargestNumberRecursive(arr, n-1, max)
}
