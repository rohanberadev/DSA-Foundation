package stronghold

const mod int = 1000000007

func CountGoodNumbers_Recursive_Brute(n int64) int {
	ans := 1

	if n-1 == 0 {
		return 5
	}

	if (n-1)%2 == 0 {
		ans *= 5
		n--
	} else {
		ans *= 4
		n--
	}

	ans *= CountGoodNumbers_Recursive_Brute(n)

	return ans % int(mod)
}

func pow(x int64, n int64) int64 {
	var ans int64 = 1
	x %= int64(mod)

	if n == 0 {
		return 1
	}

	if n%2 == 0 {
		x = x * x
		x %= int64(mod)
		n /= 2

	} else {
		ans *= x
		ans %= int64(mod)
		n -= 1
	}

	ans *= pow(x, n) % int64(mod)

	return ans % int64(mod)
}

func CountGoodNumbers_Recursive_Optimal(n int64) int {
	even := (n / 2) + (n % 2)
	odd := n / 2

	ans := pow(5, even) * pow(4, odd)

	return int(ans) % mod
}
