package arrayans

import (
	"math"
)

func MinDaysToMakeMBouquet_Myself(arr []int, m, k int) int {
	n := len(arr)
	val := m * k
	mini := math.MaxInt64
	checker := make(map[int]bool)
	if n < val {
		return -1
	}

	for i := 0; i < n; i++ {
		if checker[arr[i]] {
			continue
		}

		checker[arr[i]] = true
		mpp := make(map[int]bool)
		for j := 0; j < n; j++ {
			if arr[j] <= arr[i] {
				mpp[j] = true

			} else {
				mpp[j] = false
			}

		}
		cnt := 0
		count := 0
		for l := 0; l < n; l++ {
			if mpp[l] {
				cnt++
				if cnt == k {
					count += 1
					cnt = 0
				}

			} else {
				cnt = 0
			}
		}

		if count*k >= val {
			if mini > arr[i] {
				mini = arr[i]
			}
		}

	}

	if mini == math.MaxInt64 {
		return -1
	}

	return mini
}

func possible(arr []int, m, k, day int) bool {
	cntFlower := 0
	cntBouquet := 0

	for i := 0; i < len(arr); i++ {
		if arr[i] <= day {
			cntFlower++

			if cntFlower == k {
				cntBouquet += 1
			}

		} else {
			cntFlower = 0
		}
	}

	return cntBouquet == m
}

func MinDaysToMakeMBouquet_Brute(arr []int, m, k int) int {
	n := len(arr)
	val := m * k
	mini := math.MaxInt64
	maxi := math.MinInt64

	if val > n {
		return -1
	}

	for i := 0; i < n; i++ {
		if maxi < arr[i] {
			maxi = arr[i]
		}

		if mini > arr[i] {
			mini = arr[i]
		}
	}

	for i := mini; i <= maxi; i++ {
		if possible(arr, m, k, i) {
			return i
		}
	}

	return -1
}

func MinDaysToMakeMBouquet_Optimal(arr []int, m, k int) int {
	n := len(arr)
	mini := math.MaxInt64
	maxi := math.MinInt64

	if m*k > n {
		return -1
	}

	for i := 0; i < n; i++ {
		if maxi < arr[i] {
			maxi = arr[i]
		}

		if mini > arr[i] {
			mini = arr[i]
		}
	}

	low := mini
	high := maxi

	for low <= high {
		mid := (low + high) / 2

		if possible(arr, m, k, mid) {
			high = mid - 1

		} else {
			low = mid + 1
		}
	}

	return low
}
