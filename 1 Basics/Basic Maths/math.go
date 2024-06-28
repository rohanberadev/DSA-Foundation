package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println("Basic Maths")

	// fmt.Println(numberOfDigitsBrute(12345))
	// fmt.Println(numberOfDigitsOptimal(12345))
	// fmt.Println(reverseNumber(12345))
	// fmt.Println(checkPalindrome(4554))
	// fmt.Println(findGCDBrute(20, 15))
	// fmt.Println(findGCDBetter(9, 12))
	// fmt.Println(findGCDOptimal(20, 15))
	// fmt.Println(checkArmstrong(153))
	// displayAllDivisorBrute(36)
	// displayAllDivisorOptimal(36)
	// fmt.Println(checkPrimeNumberBrute(7))
	fmt.Println(checkPrimeNumberOptimal(9))
}

func numberOfDigitsBrute(n int) (count int) {
	count = 0
	for n > 0 {
		n /= 10
		count++
	}

	return
}

func numberOfDigitsOptimal(n int) (count int) {
	count = int(math.Log10(float64(n)) + 1)
	return
}

func reverseNumber(n int) (reverse int) {
	reverse = 0
	for n > 0 {
		reverse *= 10
		reverse += n % 10
		n /= 10
	}

	return
}

func checkPalindrome(n int) (isPalindrome bool) {
	var rev int = 0
	var original int = n
	for original > 0 {
		rev *= 10
		rev += original % 10
		original /= 10
	}

	if rev == n {
		isPalindrome = true
	} else {
		isPalindrome = false
	}

	return
}

func findGCDBrute(n1 int, n2 int) (gcd int) {
	gcd = 1

	for i := 2; i <= min(n1, n2); i++ {
		if n1%i == 0 && n2%i == 0 && gcd < i {
			gcd = i
		}
	}

	return
}

func findGCDBetter(n1 int, n2 int) (gcd int) {
	gcd = 1

	for i := min(n1, n2); i > 1; i-- {
		if n1%i == 0 && n2%i == 0 && gcd < i {
			gcd = i
		}
	}

	return
}

func findGCDOptimal(n1 int, n2 int) (gcd int) {
	gcd = 1

	for n1 > 0 && n2 > 0 {
		if n1 > n2 {
			n1 %= n2
		} else {
			n2 %= n1
		}
	}

	if n1 == 0 {
		gcd = n2
	} else if n2 == 0 {
		gcd = n1
	}

	return
}

func checkArmstrong(n int) (isArmstrong bool) {
	isArmstrong = false
	var org int = n
	var res int = 0
	var k int = numberOfDigitsOptimal(n)

	for n > 0 {
		res += int(math.Pow(float64(n%10), float64(k)))
		n /= 10
	}

	if org == res {
		isArmstrong = true
	}

	return
}

func displayAllDivisorBrute(n int) {
	for i := 1; i <= n; i++ {
		if n%i == 0 {
			fmt.Printf("%v ", i)
		}
	}
	fmt.Print("\n")
}

func displayAllDivisorOptimal(n int) {
	for i := 1; i <= int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			fmt.Printf("%v ", i)

			if i != n/i {
				fmt.Printf("%v ", n/i)
			}
		}
	}

	fmt.Print("\n")
}

func checkPrimeNumberBrute(n int) bool {
	for i := 2; i < n; i++ {
		if n%i == 0 {
			return false
		}
	}

	return true
}

func checkPrimeNumberOptimal(n int) bool {
	for i := 2; i <= int(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			return false
		}
	}

	return true
}
