package array2d

// Time :- O(M * N)
func SearchIn2DArray_Brute(mat [][]int, target int) []int {
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

func BinarySearch1D(arr []int, target int) int {
	low := 0
	high := len(arr) - 1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] == target {
			return mid
		}

		if arr[mid] < target {
			low = mid + 1

		} else {
			high = mid - 1
		}
	}

	return -1
}

// Time :- O(M * Log N)
func SearchIn2DArray_Better(mat [][]int, target int) []int {
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

// Time :- O(Log (M * N))
func SearchIn2DArray_Optimal(mat [][]int, target int) []int {
	m := len(mat)
	n := len(mat[0])

	low := 0
	high := m*n - 1

	for low <= high {
		mid := (low + high) / 2
		row := mid / n
		col := mid % n

		if mat[row][col] == target {
			return []int{row, col}
		}

		if mat[row][col] < target {
			low = mid + 1
		} else {
			high = mid - 1
		}

	}

	return []int{-1, -1}
}
