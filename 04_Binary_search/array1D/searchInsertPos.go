package array1d

func SearchInsertPos(arr []int, k int) [][]int {
	n := len(arr)
	low := 0
	high := n - 1
	index := n

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] >= k {
			high = mid - 1
			index = mid

		} else {
			low = mid + 1
		}
	}

	if index == n {
		temp := make([]int, n+1)
		temp = append(temp, k)
		return [][]int{temp, {index}}

	}

	if arr[index] != k {
		temp := make([]int, 0, n+1)

		for i := 0; i < n; i++ {
			if i == index {
				temp = append(temp, k)
				temp = append(temp, arr[i])

			} else {
				temp = append(temp, arr[i])
			}
		}

		return [][]int{temp, {index}}
	}

	return [][]int{arr, {index}}
}
