package main

import "fmt"

func main() {
	var arr = []int{1, 2, 2, 5, 9, 1, 9}
	// countRepetition(arr)
	// countRepetitionHashing(arr, 9)
	findHighestAndLowestFreq(arr, 9)
}

func countRepetition(arr []int) {
	for i := 0; i < len(arr); i++ {
		num := arr[i]
		count := 0
		if num != -1 {
			for j := i; j < len(arr); j++ {
				if num == arr[j] {
					arr[j] = -1
					count++
				}
			}
		}
		if num != -1 {
			fmt.Printf("%v occurs %v times in an array.\n", num, count)
		}
	}
}

func countRepetitionHashing(arr []int, max int) {
	hash := make(map[int]int)

	for i := 0; i <= max; i++ {
		hash[i] = 0
	}

	for i := 0; i < len(arr); i++ {
		hash[arr[i]] += 1
	}

	for key, value := range hash {
		if value > 0 {
			fmt.Printf("%v occurs %v times in an array.\n", key, value)
		}
	}

}

func findHighestAndLowestFreq(arr []int, max int) {
	hash := make(map[int]int)
	high := make([]int, 2)
	low := make([]int, 2)
	low[1] = 1

	for i := 0; i <= max; i++ {
		hash[i] = 0
	}

	for i := 0; i < len(arr); i++ {
		hash[arr[i]] += 1
	}

	for key, value := range hash {
		if value > 0 {
			if value > high[1] {
				high[0] = key
				high[1] = value
			}
			if value <= low[1] {
				low[0] = key
				low[1] = value
			}
		}
	}

	fmt.Printf("%v has the lowest frequency with %v repetions.\n", low[0], low[1])
	fmt.Printf("%v has the highest frequency with %v repetions.\n", high[0], high[1])
}
