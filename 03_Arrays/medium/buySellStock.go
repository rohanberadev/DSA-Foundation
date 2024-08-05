package medium

import "math"

func Buy_SellStockBrute(arr []int) int {
	n := len(arr)
	buy := arr[0]
	buyIndex := -1

	for i := 0; i < n; i++ {
		if buy > arr[i] {
			buy = arr[i]
			buyIndex = i
		}
	}

	sell := buy

	for i := buyIndex + 1; i < n; i++ {
		if sell < arr[i] {
			sell = arr[i]
		}
	}

	return sell - buy
}

func Buy_SellStockOptimal(arr []int) int {
	n := len(arr)
	minprice := math.MaxInt64
	maxProfit := 0

	for i := 0; i < n; i++ {
		minprice = int(math.Min(float64(minprice), float64(arr[i])))
		maxProfit = int(math.Max(float64(maxProfit), float64(arr[i]-minprice)))
	}

	return maxProfit
}
