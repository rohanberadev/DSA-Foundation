package medium

func CountSubArraysBrute(arr []int, k int) int {
	n := len(arr)
	count := 0

	for i := 0; i < n; i++ {
		sum := 0
		for j := i; j < n; j++ {
			sum += arr[j]
			if sum == k {
				count++
				break
			}
		}
	}

	return count
}

func CountSubArraysHashing(arr []int, k int) int {
	n := len(arr)
	count := 0
	prefixMap := make(map[int]int)
	prefixSum := 0

	for i := 0; i < n; i++ {
		prefixSum += arr[i]

		if prefixSum == k {
			count++
		}

		rem := prefixSum - k

		if _, ok := prefixMap[rem]; ok {
			count++
		}

		if _, ok := prefixMap[prefixSum]; !ok {
			prefixMap[prefixSum] = i
		}
	}

	return count
}

func CountSubArraysOptimal(arr []int, k int) int {
	n := len(arr)
	left := 0
	right := 0
	count := 0

	sum := arr[0]

	for right < n {
		for left <= right && sum > k {
			sum -= arr[left]
			left++
		}

		if sum == k {
			count++
		}

		right++
		if right < n {
			sum += arr[right]
		}
	}

	return count
}
