package main

import (
	"math"
	"slices"
)

func main() {

}

func Demo(arr []int, k int) {
	n := len(arr)
	distances := make([]int, 0, n)

	slices.Sort(arr)

	for i := 0; i < n; i++ {
		temp := make([]int, 0, n)
		for j := i + 1; j < n; j++ {
			temp = append(temp, arr[j]-arr[i])
		}
		minDist := math.MaxInt64
		for k := 0; k < len(temp); k++ {
			if minDist > temp[k] {
				minDist = temp[k]
			}
		}

		distances = append(distances, minDist)
	}

	slices.Sort(distances)

	for i := len(distances) - 1; i >= 0; i-- {

	}
}
