package array

func CountMaxConsecutiveOnes(arr []int) int {
	i := 0
	n := len(arr)
	max := 0
	count := 0

	for i < n {
		if arr[i] == 1 {
			count++

		}

		if arr[i] == 0 || i == n-1 {
			if max < count {
				max = count
				count = 0
			}
		}

		i++
	}

	return max
}
