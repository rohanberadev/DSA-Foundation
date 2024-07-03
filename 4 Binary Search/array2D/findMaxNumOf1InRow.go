package array2d

// Time :- O(M * N)
func FindMaxNumberOf1InRow_Brute(mat [][]int) int {
	row := len(mat)
	col := len(mat[0])

	index := -1
	maxAns := 0

	for i := 0; i < row; i++ {
		count := 0
		for j := 0; j < col; j++ {
			if mat[i][j] == 1 {
				count++
			}
		}
		if maxAns < count {
			maxAns = count
			index = i
		}
	}

	return index
}

func FindFirstOccurence(arr []int, n, target int) int {
	low := 0
	high := n - 1
	ans := -1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] >= target {
			ans = mid
			high = mid - 1

		} else {
			low = mid + 1
		}
	}

	return ans
}

func LastOcurrence(arr []int, n, target int) int {
	low := 0
	high := n - 1
	ans := -1

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] <= target {
			ans = mid
			low = mid + 1
		} else {
			high = mid - 1
		}
	}

	return ans
}

func FindMaxNumberOf1InRow_Optimal(mat [][]int) int {
	row := len(mat)

	count_max := 0
	index := -1

	for i := 0; i < row; i++ {
		col := len(mat[i])
		firstOccurenceOf1 := FindFirstOccurence(mat[i], col, 1)

		if firstOccurenceOf1 > -1 {
			lastOccurenceOf1 := FindFirstOccurence(mat[i], col, 1)
			count := lastOccurenceOf1 - firstOccurenceOf1 + 1
			if count > count_max {
				count_max = count
				index = i
			}
		}
	}

	return index
}
