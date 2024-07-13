package stronghold

var num int
var sign int = 1

func checkIfNum(b byte) bool {
	return b >= '0' && b <= '9'
}

func checkSign(b byte) bool {
	return b == '-' || b == '+'
}

func Atoi_Recursive(s string) int {
	n := len(s)

	if len(s) == 0 {
		return 0
	}

	if s[0] != ' ' && !checkSign(s[0]) && !checkIfNum(s[0]) {
		return num
	}

	if s[0:1] == " " {
		s = s[1:n]

	} else if checkIfNum(s[0]) {
		num *= 10
		num += int(s[0] - '0')
		s = s[1:n]

	} else if num == 0 && s[0] == '-' {
		sign *= -1
		s = s[1:n]

	} else if s[0] == '+' {
		s = s[1:n]

	} else {
		return num
	}

	Atoi_Recursive(s)

	return num * sign
}
