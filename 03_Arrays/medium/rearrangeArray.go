// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

package medium

func RearrangeBySignBrute(arr []int) []int {
	n := len(arr)
	var pos []int
	var neg []int

	for i := 0; i < n; i++ {
		if arr[i] > 0 {
			pos = append(pos, arr[i])

		} else {
			neg = append(neg, arr[i])
		}
	}

	for i := 0; i < n/2; i++ {
		arr[2*i] = pos[i]
		arr[2*i+1] = neg[i]
	}

	return arr
}

func RearrangeBySignOptimal(arr []int) []int {
	n := len(arr)
	posIndex := 0
	negIndex := 1
	ans := make([]int, n)

	for i := 0; i < n; i++ {
		if arr[i] < 0 {
			ans[negIndex] = arr[i]
			negIndex += 2

		} else {
			ans[posIndex] = arr[i]
			posIndex += 2
		}
	}

	return ans
}

func RearrangeBySignVariety2(arr []int) []int {
	n := len(arr)
	var pos []int
	var neg []int

	for i := 0; i < n; i++ {
		if arr[i] > 0 {
			pos = append(pos, arr[i])

		} else {
			neg = append(neg, arr[i])
		}
	}

	if len(pos) > len(neg) {
		for i := 0; i < len(neg); i++ {
			arr[i*2] = pos[i]
			arr[i*2+1] = neg[i]
		}

		index := len(neg) * 2

		for i := len(neg); i < len(pos); i++ {
			arr[index] = pos[i]
			index++
		}

	} else {
		for i := 0; i < len(pos); i++ {
			arr[i*2] = pos[i]
			arr[i*2+1] = neg[i]
		}

		index := len(pos) * 2

		for i := len(pos); i < len(neg); i++ {
			arr[index] = neg[i]
			index++
		}
	}

	return arr
}
