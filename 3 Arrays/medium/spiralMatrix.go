package medium

// Time :- O(M * N) Space :- O(M * N)
func SpiralMatrix(matrix [][]int) []int {
	row := len(matrix)
	col := len(matrix[0])
	ans := make([]int, 0, row*col)

	top := 0
	left := 0
	right := col - 1
	bottom := row - 1

	for top <= bottom && left <= right {

		// From left to right
		for i := left; i <= right; i++ {
			ans = append(ans, matrix[top][i])
		}
		top++

		// From top to bottom
		for i := top; i <= bottom; i++ {
			ans = append(ans, matrix[i][right])
		}
		right--

		// From right to left
		if top <= bottom {
			for i := right; i >= left; i-- {
				ans = append(ans, matrix[bottom][i])
			}
			bottom--
		}

		// From bottom to top
		if left <= right {
			for i := bottom; i >= top; i-- {
				ans = append(ans, matrix[i][left])
			}
			left++
		}
	}

	return ans
}
