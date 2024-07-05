package array2d

func FindMedian(arr []int) float64 {
	n := len(arr)
	if n%2 == 0 {
		median := float64(arr[n/2]+arr[(n/2)-1]) / 2.0
		return median
	}

	return float64(arr[n/2])
}

func FindMedianInRowWiseSortedMat_Brute(mat [][]int) float64 {
	m := len(mat)
	temp := make([]float64, 0, m)

	for i := 0; i < m; i++ {
		temp = append(temp, FindMedian(mat[i]))
	}

	if m%2 == 0 {
		median := temp[m/2] + temp[(m/2)-1]/2.0
		return median
	}

	return temp[m/2]
}
