package arrayans

import "math"

func loadWeight(arr []int, cap int) int {
	n := len(arr)
	day := 1
	load := 0
	for i := 0; i < n; i++ {
		if load+arr[i] > cap {
			day++
			load = arr[i]

		} else {
			load += arr[i]
		}
	}

	return day
}

// Time :- O()
func FindLowestCapacityShipPackagesWithinDays_Brute(arr []int, d int) int {
	n := len(arr)
	sum := 0
	maxi := math.MinInt64
	for i := 0; i < n; i++ {
		sum += arr[i]
		if maxi < arr[i] {
			maxi = arr[i]
		}
	}

	if d == 1 {
		return sum
	}

	for i := maxi; i <= sum; i++ {
		if loadWeight(arr, i) <= d {
			return i
		}
	}

	return sum
}

func FindLowestCapacityShipPackagesWithinDays_Optimal(arr []int, d int) int {
	n := len(arr)
	sum := 0
	maxi := math.MinInt64
	for i := 0; i < n; i++ {
		sum += arr[i]
		if maxi < arr[i] {
			maxi = arr[i]
		}
	}

	if d == 1 {
		return sum
	}

	low := maxi
	high := sum

	for low <= high {
		mid := (low + high) / 2

		if loadWeight(arr, mid) <= d {
			high = mid - 1

		} else {
			low = mid + 1
		}
	}

	return low
}
