package subsequencepattern

import "fmt"

func generatePowerSet_recursive_util(i int, j int, n int, s string) {
	if i == n {
		fmt.Println("")
		return
	}

	if j == n {
		generatePowerSet_recursive_util(i+1, i+2, n, s)
	}

	if j < n {
		fmt.Printf("%c\n", s[i])
		fmt.Printf("%c%c\n", s[i], s[j])
		fmt.Printf("%c%s\n", s[i], s[j:n])

		generatePowerSet_recursive_util(i, j+1, n, s)
	}
}

func GeneratePowerSet_Recursive(s string) {
	generatePowerSet_recursive_util(0, 1, len(s), s)
}
