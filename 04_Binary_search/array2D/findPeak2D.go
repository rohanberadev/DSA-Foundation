package array2d

import "math"

// Time :- O(M * N)
func FindPeak2D_Brute(mat [][]int) []int {
	m := len(mat)
	n := len(mat[0])

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			top := -1
			left := -1
			bottom := -1
			right := -1

			if i > 0 {
				top = mat[i-1][j]
			}
			if j > 0 {
				left = mat[i][j-1]
			}
			if i < m-1 {
				bottom = mat[i+1][j]
			}
			if j < n-1 {
				right = mat[i][j+1]
			}

			if mat[i][j] > top && mat[i][j] > bottom && mat[i][j] > left && mat[i][j] > right {
				return []int{i, j}
			}
		}
	}

	return []int{-1, -1}
}

func FindMaxElementCol(mat [][]int, colIndex, m int) int {
	maxAns := math.MinInt64
	rowIndex := -1
	for i := 0; i < m; i++ {
		if maxAns < mat[i][colIndex] {
			maxAns = mat[i][colIndex]
			rowIndex = i
		}
	}

	return rowIndex
}

func FindPeak2D_Optimal(mat [][]int) []int {
	m := len(mat)
	n := len(mat[0])

	low := 0
	high := n - 1

	for low <= high {
		mid := (low + high) / 2
		rowIndex := FindMaxElementCol(mat, mid, m)
		maxElem := mat[rowIndex][mid]

		left := -1
		right := -1

		if mid-1 >= 0 {
			left = mat[rowIndex][mid-1]
		}
		if mid+1 < n {
			right = mat[rowIndex][mid+1]
		}

		if maxElem > left && maxElem > right {
			return []int{rowIndex, mid}

		} else if maxElem < right {
			low = mid + 1

		} else {
			high = mid - 1
		}
	}

	return []int{-1, -1}
}
