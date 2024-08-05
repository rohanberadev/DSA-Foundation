package hard

import "fmt"

func nCr(n, r int) int {
	res := 1
	for i := 0; i < r; i++ {
		res = res * (n - i)
		res = res / (i + 1)
	}

	return res
}

func PascalTriangleVariety1(r, c int) int {
	ans := nCr(r-1, c-1)

	return ans
}

func PascalTriangleVariety2(n int) {
	for i := 0; i < n; i++ {
		ans := nCr(n-1, i)
		fmt.Printf("%v ", ans)
	}
}

func PascalTriangleVariety3(n int) {
	for i := 0; i < n; i++ {
		for s := 0; s < n-i; s++ {
			fmt.Print(" ")
		}

		for j := 0; j <= i; j++ {
			ans := nCr(i, j)
			fmt.Printf("%v ", ans)
		}
		fmt.Print("\n")
	}
	fmt.Print("\n")
}
