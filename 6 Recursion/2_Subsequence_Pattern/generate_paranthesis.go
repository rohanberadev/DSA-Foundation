package subsequencepattern

func generateParanthesis_recursive(pos int, open int, close int, n int, s string) []string {
	ans := make([]string, 0, 100)

	if pos == n*2 {
		ans = append(ans, s)
		return ans
	}

	if open < n {
		temp := s
		temp += "("
		ans = append(ans, generateParanthesis_recursive(pos+1, open+1, close, n, temp)...)
	}

	if open > close {
		s += ")"
		ans = append(ans, generateParanthesis_recursive(pos+1, open, close+1, n, s)...)
	}

	return ans
}

func GenerateParathesis(n int) []string {
	ans := generateParanthesis_recursive(0, 0, 0, n, "")

	return ans
}
