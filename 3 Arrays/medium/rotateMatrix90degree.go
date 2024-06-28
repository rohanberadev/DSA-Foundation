package medium

func RotateMatrix90DegreeBrute(arr [][]int, n int) [][]int {
	rotated := make([][]int, n)
	for i := 0; i < n; i++ {
		rotated[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			rotated[j][n-i-1] = arr[i][j]
		}
	}

	return rotated
}

func RotateMatrix90DegreeOptimal(matrix [][]int, n int) [][]int {
	// Transpose
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			temp := matrix[i][j]
			matrix[i][j] = matrix[j][i]
			matrix[j][i] = temp
		}
	}

	// reverse the columns
	for i := 0; i < n; i++ {
		l := 0
		r := n - 1
		for l < r {
			temp := matrix[i][l]
			matrix[i][l] = matrix[i][r]
			matrix[i][r] = temp
			l++
			r--
		}
	}

	return matrix
}

func TransposeBrute(matrix [][]int, row, col int) [][]int {
	transpose := make([][]int, col)

	for i := 0; i < col; i++ {
		transpose[i] = make([]int, row)
	}

	for j := 0; j < col; j++ {
		for i := 0; i < row; i++ {
			transpose[j][i] = matrix[i][j]
		}
	}

	return transpose
}

func TransposeOptimal(matrix [][]int, n int) [][]int {

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			temp := matrix[i][j]
			matrix[i][j] = matrix[j][i]
			matrix[j][i] = temp
		}
	}

	return matrix
}
