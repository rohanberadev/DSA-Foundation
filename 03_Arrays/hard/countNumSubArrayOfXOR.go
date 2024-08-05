package hard

// Time :- O(N^3) Space :- O(1)
func CountNumSubArrayWithXorKBrute(arr []int, k int) int {
	n := len(arr)
	count := 0

	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			xor := 0

			for k := i; k <= j; k++ {
				xor = xor ^ arr[k]
			}

			if xor == k {
				count++
			}
		}
	}

	return count
}

// Time :- O(N^2) Space :- O(1)
func CountNumSubArrayWithXorKBetter(arr []int, k int) int {
	n := len(arr)
	count := 0

	for i := 0; i < n; i++ {
		xor := 0
		for j := i; j < n; j++ {
			xor = xor ^ arr[j]

			if xor == k {
				count++
			}
		}
	}

	return count
}

// Time :- O(N) Space :- O(N)
func CountNumSubArrayWithXorKHashing(arr []int, k int) int {
	n := len(arr)
	xorMap := make(map[int]int)
	xor := 0
	xorMap[xor] += 1
	count := 0

	for i := 0; i < n; i++ {
		xor = xor ^ arr[i]

		x := xor ^ k
		count += xorMap[x]
		xorMap[xor] += 1
	}

	return count
}
