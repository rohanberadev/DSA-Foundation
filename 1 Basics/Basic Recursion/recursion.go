package main

import (
	"fmt"
)

func main() {
	// printName(5)
	// printOneToN(5)
	// printNToOne(5)
	// fmt.Print(sumOfNumber(5))
	// fmt.Println(factorial(5))
	// printArray([]int{1, 2, 3, 4, 5}, 5)
	// n := 5
	// arr := []int{1, 2, 3, 4, 5}
	// printArray(reverseArrayUsingAux(arr, n), n)
	// printArray(reverseArrayUsingPointer(arr, n), n)
	// printArray(reverseArrayUsingRecursion(arr, 0, n-1), n)
	// fmt.Println(checkStringPalidrome("rohan"))
	// fmt.Println(checkStringPalidromeRecursion("rohan", 0))
	// fibonacii(5)
	// for i := 0; i < 5; i++ {
	// 	fmt.Printf("%v ", fibonaciiRecursion(i))
	// }
}

func printName(n int) {
	if n == 0 {
		return
	}

	fmt.Println("Rohan")
	printName(n - 1)
}

func printOneToN(n int) {
	if n == 0 {
		return
	}

	printOneToN(n - 1)

	fmt.Printf("%v\n", n)
}

func printNToOne(n int) {
	if n == 0 {
		return
	}

	fmt.Printf("%v\n", n)
	printNToOne(n - 1)
}

func sumOfNumber(n int) int {
	if n == 1 {
		return 1
	}
	return n + sumOfNumber(n-1)
}

func factorial(n int) int {
	if n <= 1 {
		return n
	}

	return n * factorial(n-1)
}

func printArray(arr []int, len int) {
	for i := 0; i < len; i++ {
		fmt.Printf("%v ", arr[i])
	}
	fmt.Print("\n")
}

func reverseArrayUsingAux(arr []int, len int) []int {
	var aux = make([]int, len)

	for i := len - 1; i >= 0; i-- {
		aux[i] = arr[len-i-1]
	}

	return aux
}

func reverseArrayUsingPointer(arr []int, len int) []int {
	var i int = 0
	var j int = len - 1

	for i < j {
		temp := arr[i]
		arr[i] = arr[j]
		arr[j] = temp
		i++
		j--
	}

	return arr
}

func reverseArrayUsingRecursion(arr []int, start int, end int) []int {
	if start >= end {
		return arr
	}
	temp := arr[start]
	arr[start] = arr[end]
	arr[end] = temp
	return reverseArrayUsingRecursion(arr, start+1, end-1)
}

func checkStringPalidrome(str string) bool {
	var start int = 0
	var end int = len(str) - 1

	for start < end {
		if str[start] != str[end] {
			return false
		}
		start++
		end--
	}

	return true
}

func checkStringPalidromeRecursion(str string, i int) bool {
	if i >= len(str)-i-1 {
		return true
	} else if str[i] != str[len(str)-i-1] {
		return false
	}

	return checkStringPalidromeRecursion(str, i+1)
}

func fibonacii(n int) {
	var t1 int = 0
	var t2 int = 0
	var t3 int = 1

	for i := 0; i < n; i++ {
		t1 = t2
		t2 = t3
		t3 = t1 + t2
		fmt.Printf("%v ", t1)
	}
}

func fibonaciiRecursion(n int) int {
	if n <= 1 {
		return n
	}

	return fibonaciiRecursion(n-1) + fibonaciiRecursion(n-2)
}

func GenratePermutation1() {

}
