package medium

import "fmt"

func PrintMatrix(arr [][]int, row, col int) {
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			fmt.Printf("%v ", arr[i][j])
		}
		fmt.Print("\n")
	}
	fmt.Print("\n\n")
}

func SetMatrixZeroBrute(arr [][]int, row, col int) [][]int {
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if arr[i][j] == 0 {
				for m := 0; m < row; m++ {
					arr[m][j] = -1
				}

				for n := 0; n < col; n++ {
					arr[i][n] = -1
				}
			}
		}
	}

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if arr[i][j] == -1 {
				arr[i][j] = 0
			}
		}
	}

	return arr
}

func SetMatrixZeroBetter(arr [][]int, row, col int) [][]int {
	markRow := make([]bool, row)
	markCol := make([]bool, col)

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if arr[i][j] == 0 {
				markRow[i] = true
				markCol[j] = true
			}
		}
	}

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if markRow[i] || markCol[j] {
				arr[i][j] = 0
			}
		}
	}

	return arr
}

func SetMatrixZeroOptimal(arr [][]int, row, col int) [][]int {
	col0 := 1

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if arr[i][j] == 0 {
				if j == 0 {
					col0 = 0

				} else {
					arr[0][j] = 0
					arr[i][0] = 0
				}
			}
		}
	}

	if col0 == 0 {
		for i := 0; i < row; i++ {
			arr[i][0] = 0
		}
	}

	for j := 0; j < col; j++ {
		if arr[0][j] == 0 {
			for i := 0; i < row; i++ {
				arr[i][j] = 0
			}
		}
	}

	for i := 0; i < row; i++ {
		if arr[i][0] == 0 {
			for j := 0; j < col; j++ {
				arr[i][j] = 0
			}
		}
	}

	return arr
}
