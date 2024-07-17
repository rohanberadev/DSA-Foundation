package subsequencepattern

import "fmt"

func generateBinaryString_recursive(n int, K int, s string) {
	if n == K {
		fmt.Println(s)
		return
	}

	if s[n-1] == '0' {
		temp := s
		s += "0"
		generateBinaryString_recursive(n+1, K, s)

		temp += "1"
		generateBinaryString_recursive(n+1, K, temp)

	}

	if s[n-1] == '1' {
		s += "0"
		generateBinaryString_recursive(n+1, K, s)
	}

}

func GenerateBinaryStrings(K int) {
	if K <= 0 {
		return
	}

	s := "0"
	generateBinaryString_recursive(1, K, s)

	s = "1"
	generateBinaryString_recursive(1, K, s)
}
