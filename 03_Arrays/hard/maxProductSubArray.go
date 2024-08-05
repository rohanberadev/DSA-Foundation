package hard

import "math"

func MaxProductSubarrayBrute(arr []int) int {
	n := len(arr)
	maxPro := math.MinInt64

	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			pro := 1

			for k := i; k <= j; k++ {
				pro *= arr[k]
			}
			if maxPro < pro {
				maxPro = pro
			}
		}
	}

	return maxPro
}

func MaxProductSubarrayBetter(arr []int) int {
	n := len(arr)
	maxPro := math.MinInt64

	for i := 0; i < n; i++ {
		pro := 1
		for j := i; j < n; j++ {
			pro *= arr[j]

			if maxPro < pro {
				maxPro = pro
			}
		}
	}

	return maxPro
}

func MaxProductSubarrayOptimal1(arr []int) int {
	n := len(arr)
	maxPro := math.MinInt64
	prefix := 1
	suffix := 1

	for i := 0; i < n; i++ {
		if prefix == 0 {
			prefix = 1
		}
		if suffix == 0 {
			suffix = 1
		}

		prefix *= arr[i]
		suffix *= arr[n-i-1]

		maxPro = int(math.Max(float64(maxPro), math.Max(float64(prefix), float64(suffix))))
	}

	return maxPro
}

func MaxProductSubarrayOptimal2(arr []int) int {
	n := len(arr)
	maxPro := math.MinInt64
	prod1 := arr[0]
	prod2 := arr[0]

	for i := 0; i < n; i++ {
		temp := maxOf(arr[i], prod1*arr[i], prod2*arr[i])
		prod2 = minOf(arr[i], prod1*arr[i], prod2*arr[i])
		prod1 = temp

		maxPro = int(math.Max(float64(maxPro), float64(prod1)))
	}

	return maxPro
}

func maxOf(a, b, c int) int {
	return int(math.Max(float64(a), math.Max(float64(b), float64(c))))
}

func minOf(a, b, c int) int {
	return int(math.Min(float64(a), math.Min(float64(b), float64(c))))
}
