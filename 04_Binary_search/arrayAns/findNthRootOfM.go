package arrayans

import "math/big"

func pow(m, n int) int {
	ans := 1
	for i := 1; i <= n; i++ {
		ans *= m
	}

	return ans
}

// Time :- O(N ^ 2)
func FindNthRootOfM_Brute(m, n int) int {
	for i := 1; i <= m; i++ {
		if pow(i, n) == m {
			return i
		}
	}

	return -1
}

func pow_optimal_func(x, m, n int) int {
	ans := big.NewInt(1)

	for i := 1; i <= n; i++ {
		product := new(big.Int)
		ans = product.Mul(ans, big.NewInt(int64(x)))
		if ans.Cmp(big.NewInt(int64(m))) == 1 {
			return 2
		}
	}

	if ans.Cmp(big.NewInt(int64(m))) == 0 {
		return 1
	}

	return 0
}

// Time :- O(N Log N)
func FindNthRootOfM_Optimal(m, n int) int {
	low := 1
	high := m

	for low <= high {
		mid := (low + high) / 2
		midN := pow_optimal_func(mid, m, n)

		if midN == 1 {
			return mid

		} else if midN == 0 {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}

	return -1
}
