package arrayans

// Time :- O(N)
func FindSqrtOfNBrute(n int) int {
	ans := 0
	for i := 1; i <= n; i++ {
		if i*i <= n {
			ans = i

		} else {
			break
		}
	}

	return ans
}

// Time :- O(Log N)
func FindSqrtOfNOptimal(n int) int {
	low := 1
	high := n
	ans := 0

	for low <= high {
		mid := (low + high) / 2

		if mid*mid <= n {
			ans = mid
			low = mid + 1

		} else {
			high = mid - 1
		}
	}

	return ans
}
