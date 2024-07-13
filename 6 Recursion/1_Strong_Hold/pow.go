package stronghold

func Pow_Iterative(x float64, n int) float64 {
	ans := 1.0
	nn := n
	if n < 0 {
		n = -1 * n
	}

	for n > 0 {
		if n%2 == 0 {
			x = x * x
			n = n / 2
		} else {
			ans *= x
			n = n - 1
		}
	}
	if nn < 0 {
		return 1.0 / ans
	}

	return ans
}

func Pow_Recursive(x float64, n int) float64 {
	ans := 1.0
	inverse := false

	if n < 0 {
		n = -1 * n
		inverse = true
	}

	if n == 0 {
		return 1
	}

	if n%2 == 0 {
		x = x * x
		n = n / 2

	} else {
		ans *= x
		n = n - 1
	}

	ans *= Pow_Recursive(x, n)

	if inverse {
		return 1.0 / ans
	} else {
		return ans
	}
}
