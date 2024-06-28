package main

import (
	"fmt"
)

func main() {
	// rectangleStar(5, 5)
	// rightAngleTriangleStar1(5)
	// rightAngleTriangleNumber1(5)
	// rightAngleTriangleNumber2(5)
	// rightAngleTriangleStar2(5)
	// rightAngleTriangleNumber3(5)
	// pyramid1(5)
	// pyramid2(5)
	// diamond(5)
	// halfDiamond(5)
	// rightAngleTriangleNumber4(5)
	// mahindraLogoNumber(4)
	// rightAngleTriangleNumber5(5)
	// rightAngleTriangleAlphabet1(5)
	// rightAngleTriangleAlphabet3(5)
	// pyramidAlphabet1(5)
	// rightAngleTriangleAlphabet4(5)
	// window(5)
	// butterfly(5)
	// door(5)
	rectangleNumber(4)
}

func rectangleStar(row int, col int) {
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			fmt.Print("*")
		}
		fmt.Print("\n")
	}
}

func rightAngleTriangleStar1(height int) {
	for i := 0; i < height; i++ {
		for j := 0; j <= i; j++ {
			fmt.Print("*")
		}
		fmt.Print("\n")
	}
}

func rightAngleTriangleStar2(height int) {
	for i := 0; i < height; i++ {
		for j := height; j > i; j-- {
			fmt.Print("*")
		}
		fmt.Print("\n")
	}
}

func rightAngleTriangleNumber1(height int) {
	for i := 1; i <= height; i++ {
		for j := 1; j <= i; j++ {
			fmt.Printf("%v", j)
		}
		fmt.Print("\n")
	}
}

func rightAngleTriangleNumber2(height int) {
	for i := 1; i <= height; i++ {
		for j := 1; j <= i; j++ {
			fmt.Printf("%v", i)
		}
		fmt.Print("\n")
	}
}

func rightAngleTriangleNumber3(height int) {
	for i := height; i > 0; i-- {
		for j := 1; j <= i; j++ {
			fmt.Printf("%v", j)
		}
		fmt.Print("\n")
	}
}

func rightAngleTriangleNumber4(height int) {
	for i := 0; i < height; i++ {
		for j := 0; j <= i; j++ {
			if j%2 == 0 {
				fmt.Print("1 ")
			} else {
				fmt.Print("0 ")
			}
		}
		fmt.Print("\n")
	}
}

func rightAngleTriangleNumber5(height int) {
	var count int = 1
	for i := 0; i < height; i++ {
		for j := 0; j <= i; j++ {
			fmt.Printf("%v ", count)
			count++
		}
		fmt.Print("\n")
	}
}

func pyramid1(height int) {
	for i := 0; i < height; i++ {
		for j := height; j > i; j-- {
			fmt.Print(" ")
		}

		for k := 0; k < i; k++ {
			fmt.Print("* ")
		}

		fmt.Print("\n")
	}
}

func pyramid2(height int) {
	for i := 0; i < height; i++ {
		for j := 0; j < i; j++ {
			fmt.Print(" ")
		}

		for k := height; k > i; k-- {
			fmt.Print("* ")
		}

		fmt.Print("\n")
	}
}

func diamond(n int) {
	for i := 0; i < n; i++ {
		for j := n; j > i; j-- {
			fmt.Print(" ")
		}

		for k := 0; k < i; k++ {
			fmt.Print("* ")
		}

		fmt.Print("\n")
	}

	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			fmt.Print(" ")
		}

		for k := n; k > i; k-- {
			fmt.Print("* ")
		}

		fmt.Print("\n")
	}
}

func halfDiamond(n int) {
	for i := 0; i < n-1; i++ {
		for j := 0; j <= i; j++ {
			fmt.Print("*")
		}
		fmt.Print("\n")
	}

	for i := 0; i < n; i++ {
		for j := n; j > i; j-- {
			fmt.Print("*")
		}
		fmt.Print("\n")
	}
}

func mahindraLogoNumber(n int) {
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			fmt.Printf("%v", j)
		}

		for space := 1; space <= n*2-i*2; space++ {
			fmt.Print(" ")
		}

		for k := i; k >= 1; k-- {
			fmt.Printf("%v", k)
		}
		fmt.Print("\n")
	}
}

func rightAngleTriangleAlphabet1(height int) {
	for i := 0; i < height; i++ {
		for j := 0; j <= i; j++ {
			result := rune(j + 65)
			fmt.Printf("%c", result)
		}
		fmt.Print("\n")
	}
}

func rightAngleTriangleAlphabet2(height int) {
	for i := height; i > 0; i-- {
		for j := 0; j < i; j++ {
			result := rune(j + 65)
			fmt.Printf("%c", result)
		}
		fmt.Print("\n")
	}
}

func rightAngleTriangleAlphabet3(height int) {
	for i := 0; i < height; i++ {
		for j := 0; j <= i; j++ {
			result := rune(i + 65)
			fmt.Printf("%c", result)
		}
		fmt.Print("\n")
	}
}

func rightAngleTriangleAlphabet4(height int) {
	for i := height - 1; i >= 0; i-- {
		for j := i; j < height; j++ {
			result := rune(j + 65)
			fmt.Printf("%c ", result)
		}
		fmt.Print("\n")
	}
}

func pyramidAlphabet1(height int) {
	for i := 0; i < height; i++ {
		for j := height; j > i; j-- {
			fmt.Print(" ")
		}

		for k := 0; k < 2*i+1; k++ {
			var result rune = rune(k + 65)
			if k > i {
				result = rune(i - (k - i) + 65)
			}

			fmt.Printf("%c", result)
		}

		fmt.Print("\n")
	}
}

func window(n int) {
	for i := 0; i < n; i++ {
		for j := n; j > i; j-- {
			fmt.Print("*")
		}

		for s := 0; s < 2*i; s++ {
			fmt.Print(" ")
		}

		for k := n; k > i; k-- {
			fmt.Print("*")
		}

		fmt.Print("\n")
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			fmt.Print("*")
		}

		for s := 1; s <= 2*n-2*i; s++ {
			fmt.Print(" ")
		}

		for k := 1; k <= i; k++ {
			fmt.Print("*")
		}

		fmt.Print("\n")
	}
}

func butterfly(n int) {
	for i := 1; i <= n-1; i++ {
		for j := 1; j <= i; j++ {
			fmt.Print("*")
		}

		for s := 1; s <= 2*n-2*i; s++ {
			fmt.Print(" ")
		}

		for k := 1; k <= i; k++ {
			fmt.Print("*")
		}

		fmt.Print("\n")
	}

	for i := 0; i < n; i++ {
		for j := n; j > i; j-- {
			fmt.Print("*")
		}

		for s := 0; s < 2*i; s++ {
			fmt.Print(" ")
		}

		for k := n; k > i; k-- {
			fmt.Print("*")
		}

		fmt.Print("\n")
	}
}

func door(n int) {
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if i == 1 || i == n {
				fmt.Print("*")
			} else if j == 1 || j == n {
				fmt.Print("*")
			} else {
				fmt.Print(" ")
			}
		}

		fmt.Print("\n")
	}
}

func rectangleNumber(n int) {
	for i := 0; i < 2*n-1; i++ {
		for j := 0; j < 2*n-1; j++ {
			var top int = i
			var left int = j
			var right = (2*n - 2) - j
			var bottom = (2*n - 2) - i
			var result = n - min(min(top, bottom), min(left, right))

			fmt.Printf("%v", result)
		}

		fmt.Print("\n")
	}
}
