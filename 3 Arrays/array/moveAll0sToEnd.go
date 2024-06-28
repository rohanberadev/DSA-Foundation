package array

func MoveAllZeroesToEndBrute(arr []int) []int {
	n := len(arr)
	temp := make([]int, 0, n)

	for i := 0; i < n; i++ {
		if arr[i] > 0 {
			temp = append(temp, arr[i])
		}
	}

	for i := 0; i < n; i++ {
		if arr[i] == 0 {
			temp = append(temp, arr[i])
		}
	}

	return temp
}

// O(N)
func MoveAllZeroesToEndOptimal1(arr []int) []int {
	n := len(arr) - 1
	i := 0
	j := n

	for i < j {
		for i <= n && arr[i] != 0 {
			i++
		}

		for j >= 0 && arr[j] == 0 {
			j--
		}

		if i < j {
			temp := arr[i]
			arr[i] = arr[j]
			arr[j] = temp
		}
	}

	return arr
}

func MoveAllZeroesToEndOptimal2(arr []int) []int {
	n := len(arr)
	j := -1

	for i := 0; i < n; i++ {
		if arr[i] == 0 {
			j = i
			break
		}
	}

	if j == -1 {
		return arr
	}

	for i := j + 1; i < n; i++ {
		if arr[i] != 0 {
			temp := arr[i]
			arr[i] = arr[j]
			arr[j] = temp

			j++
		}
	}

	return arr
}
