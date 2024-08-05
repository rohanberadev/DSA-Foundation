package array2d

// Time :- O(M * N)
func SearchIn2DArrayRowAndColWise_Brute(mat [][]int, target int) []int {
	row := len(mat)

	for i := 0; i < row; i++ {
		col := len(mat[i])
		for j := 0; j < col; j++ {
			if mat[i][j] == target {
				return []int{i, j}
			}
		}
	}

	return []int{-1, -1}
}

// Time :- O(M * Log N)
func SearchIn2DArrayRowAndColWise_Better(mat [][]int, target int) []int {
	row := len(mat)

	for i := 0; i < row; i++ {
		// Binary Search
		j := BinarySearch1D(mat[i], target)
		if j != -1 {
			return []int{i, j}
		}
	}

	return []int{-1, -1}
}

// Time :- O(M + N)
func SearchIn2DArrayRowAndColWise_Optimal(mat [][]int, target int) []int {
	m := len(mat)
	n := len(mat[0])

	row := 0
	col := n - 1

	for row < m && col >= 0 {
		if mat[row][col] == target {
			return []int{row, col}
		}

		if mat[row][col] < target {
			row++

		} else {
			col--
		}
	}

	return []int{-1, -1}
}
