package array

func LeftRotataArray(arr []int, k int) []int {
	n := len(arr)
	temp := make([]int, k)
	k = k % n

	for i := 0; i < k; i++ {
		temp[i] = arr[i]
	}

	for i := k; i < n; i++ {
		arr[i-k] = arr[i]
	}

	for i := n - k; i < n; i++ {
		arr[i] = temp[i-(n-k)]
	}

	return arr
}

func RightRotateArray(arr []int, k int) []int {
	n := len(arr)
	temp := make([]int, n)
	k = k % n

	for i := n - k; i < n; i++ {
		temp[i-(n-k)] = arr[i]
	}

	for i := n - k - 1; i >= 0; i-- {
		arr[i+k] = arr[i]
	}

	for i := 0; i < k; i++ {
		arr[i] = temp[i]
	}

	return arr
}
