package basics

func ReplacePI_1(s string) string {
	n := len(s)
	ans := ""

	if n <= 1 {
		return s
	}

	if s[0:2] == "pi" {
		ans += "3.14"
		s = s[2:n]

	} else {
		ans += s[0:1]
		s = s[1:n]
	}

	ans += ReplacePI_1(s)

	return ans
}
