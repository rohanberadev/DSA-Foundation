package arrayans

func pow(m, n int) int {
	ans := 1
	for i := 1; i <= n; i++ {
		ans *= m
	}

	return ans
}

// Time :- O(N)
func FindNthSqrtOfM_Brute(m, n int) int {
	for i := 1; i <= m; i++ {
		if pow(i, n) == m {
			return i
		}
	}

	return -1
}

// Time :- O(Log N)
func FindNthSqrtOfM_Optimal(m, n int) int {
	low := 1
	high := m

	for low <= high {
		mid := (low + high) / 2

		if pow(mid, n) == m {
			return mid
		}

		if pow(mid, n) < n {
			low = mid + 1

		} else {
			high = mid - 1
		}
	}

	return -1
}
