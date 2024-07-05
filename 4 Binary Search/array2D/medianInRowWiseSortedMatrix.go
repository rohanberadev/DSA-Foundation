package array2d

import (
	"math"
	"slices"
)

// Time :- O(M*N + (M*N)Log(M*N)) // Space :- O(M*N)
func FindMedianInRowWiseSortedMat_Brute(mat [][]int) int {
	m := len(mat)
	n := len(mat[0])
	temp := make([]int, 0, m*n)

	for i := 0; i < m*n; i++ {
		row := i / n
		col := i % n

		temp = append(temp, mat[row][col])
	}

	slices.Sort(temp)

	return temp[(m*n)/2]
}

func CountSmallerEquales(mat [][]int, m, n, x int) int {
	// Time :- O(M * Log N)
	cnt := 0
	for i := 0; i < m; i++ {
		// BS Upper Bound
		low := 0
		high := n - 1

		for low <= high {
			mid := (low + high) / 2

			if mat[i][mid] <= x {
				low = mid + 1

			} else {
				high = mid - 1
			}
		}
		cnt += low
	}

	return cnt
}

func FindMedianInRowWiseSortedMat_Optimal(mat [][]int) int {
	m := len(mat)
	n := len(mat[0])

	low := math.MaxInt64
	high := math.MinInt64

	req := (m * n) / 2

	for i := 0; i < m; i++ {
		if low > mat[i][0] {
			low = mat[i][0]
		}
		if high < mat[i][n-1] {
			high = mat[i][n-1]
		}
	}

	for low <= high {
		mid := (low + high) / 2
		smallerEquales := CountSmallerEquales(mat, m, n, mid)

		if smallerEquales <= req {
			low = mid + 1

		} else {
			high = mid - 1
		}
	}

	return low
}
