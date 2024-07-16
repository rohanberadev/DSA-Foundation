package stronghold

import "math"

func checkForNum(b byte) bool {
	return b >= '0' && b <= '9'
}

func Atoi_Recursive(s string) int {
	n := len(s)
	if n == 1 {
		return int(s[0] - '0')
	}

	smallAns := Atoi_Recursive(s[1:n])

	a := int(s[0] - '0')

	return smallAns + a*10
}

// Medium
func Atoi_Iterative(s string) int {
	index := 0

	for index < len(s) && s[index] == ' ' {
		index++
	}

	s = s[index:]

	sign := +1
	num := 0
	MIN := math.MinInt32
	MAX := math.MaxInt32

	if s[0] == '-' {
		sign = -1
		s = s[1:]

	} else if s[0] == '+' {
		s = s[1:]
	}

	n := len(s)

	for i := 0; i < n; i++ {
		if s[i] == ' ' || !checkForNum(s[i]) {
			break
		}

		num *= 10
		num += int(s[i] - '0')

		if sign*num < MIN {
			return MIN
		}
		if sign*num > MAX {
			return MAX
		}
	}

	return num * sign
}
