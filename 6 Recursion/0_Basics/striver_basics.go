package basics

import "fmt"

/* Part - 1 */

func PrintNamesNTimes(name string, n int) {
	if n == 0 {
		return
	}

	fmt.Println(name)
	PrintNamesNTimes(name, n-1)
}

func PrintNLinearly(i int, n int) {
	if i > n {
		return
	}

	fmt.Println(i)
	PrintNLinearly(i+1, n)
}

func PrintNReverse(n int) {
	if n == 0 {
		return
	}

	fmt.Println(n)
	PrintNReverse(n - 1)
}

func PrintNLinearly_BackTrack(n int) {
	if n == 0 {
		return
	}

	PrintNLinearly_BackTrack(n - 1)
	fmt.Println(n)
}

func PrintNReverse_BackTrack(n int) {
	if n == 0 {
		return
	}

	fmt.Println(n)
	PrintNReverse_BackTrack(n - 1)
}

/* Part - 2 */

func SumOfN_Parameterized_1(n int, sum int) {
	if n == 0 {
		fmt.Println(sum)
		return
	}

	SumOfN_Parameterized_1(n-1, sum+n)
}

func SumOfN_Parameterized_2(n int, sum int) int {
	if n == 0 {
		return sum
	}

	return SumOfN_Parameterized_2(n-1, sum+n)
}

func SumOfN_Functional(n int) int {
	if n == 0 {
		return n
	}

	return n + SumOfN_Functional(n-1)
}

func FactorialOfN(n int) int {
	if n == 0 {
		return 1
	}

	return n * FactorialOfN(n-1)
}

/* Part - 3 */
func ReverseAnArray_Pointer(l int, r int, arr []int) {
	if l >= r {
		return
	}

	// swap
	arr[l], arr[r] = arr[r], arr[l]

	ReverseAnArray_Pointer(l+1, r-1, arr)
}

func ReverseAnArray_Parameterized(arr []int, i int) {
	n := len(arr)

	if i >= n/2 {
		return
	}

	// swap
	arr[i], arr[n-i-1] = arr[n-i-1], arr[i]

	ReverseAnArray_Parameterized(arr, i+1)
}

func CheckPalindrome_Functional_Pointers(s string, l, r int) bool {
	if l >= r {
		return true
	}

	if s[l] != s[r] {
		return false
	}

	return CheckPalindrome_Functional_Pointers(s, l+1, r-1)
}

func CheckPalindrome_Functional_Parameterized(s string, i int) bool {
	n := len(s)

	if i >= n/2 {
		return true
	}

	if s[i] != s[n-i-1] {
		return false
	}

	return CheckPalindrome_Functional_Parameterized(s, i+1)
}

/* Part-4 */
// Time :- O(2^N)
func Fibonacci_Brute(n int) int {
	if n <= 1 {
		return n
	}

	return Fibonacci_Brute(n-1) + Fibonacci_Brute(n-2)
}

var fib = make([]int, 1000)

func fib_memoize(n int) int {
	if n <= 1 {
		return n
	}

	if fib[n] != -1 {
		return fib[n]

	} else {
		fib[n] = fib_memoize(n-1) + fib_memoize(n-2)
		return fib[n]
	}

}

func Fibonacci_Optimal(n int) int {
	for i := 0; i < len(fib); i++ {
		fib[i] = -1
	}
	return fib_memoize(n)
}
