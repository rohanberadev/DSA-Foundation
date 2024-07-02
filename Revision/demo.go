package main

import (
	"fmt"
	"math"
)

func main() {
	// Test cases
	arr := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	fmt.Println(MinimizeMaxDistGasStations_Brute(arr, 9))
}

func MaximumDist(arr []int, dist float64, k int) float64 {
	n := len(arr)
	maxDist := 0.0

	for i := 0; i < n; i++ {
		lastSt := float64(arr[i]) + dist
		maxD := float64(arr[i]) - lastSt
		stations := 1

		for j := i + 1; j < n; j++ {
			d := float64(arr[j]) - lastSt
			if d > maxD {
				maxD = d
			}

			lastSt = float64(arr[j]) + dist
			stations++
		}

		if stations == k && maxD > maxDist {
			maxDist = maxD
		}
	}

	if maxDist < dist {
		return dist
	}

	return maxDist
}

func MinimizeMaxDistGasStations_Brute(arr []int, k int) float64 {
	n := len(arr)
	low := 0.1
	high := (float64(arr[n-1]) - float64(arr[0])) / (float64(k) + 1.0)

	if n == k {
		return high
	}

	minDist := math.MaxFloat64

	for dist := low; dist <= high; dist += 0.1 {
		// fmt.Println(dist)
		d := MaximumDist(arr, dist, k)
		if d < minDist {
			minDist = d
		} else {
			break
		}
	}

	return minDist
}
