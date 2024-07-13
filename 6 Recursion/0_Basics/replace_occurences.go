package basics

func ReplaceOccurences(s string, target string) string {
	n := len(s)
	ans := ""

	if n == 0 {
		return ""
	}

	if s[0:1] != target {
		ans += s[0:1]
		s = s[1:n]

	} else {
		s = s[1:n]
	}

	ans += ReplaceOccurences(s, target)

	return ans
}
