package basics

func FindFisrtIndexOfElemArray_1(arr []int, key, n, ans int) int {
	if n == 0 {
		return ans
	}

	if arr[n-1] == key {
		ans = n - 1
	}

	return FindFisrtIndexOfElemArray_1(arr, key, n-1, ans)
}

func FindFisrtIndexOfElemArray_2(arr []int, key, ans int) int {
	if len(arr) == 0 {
		return ans
	}

	if arr[len(arr)-1] == key {
		ans = len(arr) - 1
	}

	return FindFisrtIndexOfElemArray_2(arr[0:len(arr)-1], key, ans)
}

func FindFisrtIndexOfElemArray_3(arr []int, key int) int {
	if len(arr) == 0 {
		return -1

	} else if arr[0] == key {
		return 0

	} else {
		ans := FindFisrtIndexOfElemArray_3(arr[1:], key)

		if ans == -1 {
			return -1

		} else {
			return ans + 1
		}
	}
}
