package array

func MergeSort(arr *[]int, low, high int) {
	if low >= high {
		return
	}

	var mid int = (low + high) / 2

	MergeSort(arr, low, mid)
	MergeSort(arr, mid+1, high)

	Merge(arr, low, mid, high)
}

func Merge(arr *[]int, low, mid, high int) {
	left := low
	right := mid + 1
	temp := make([]int, 0, high+1)

	for left <= mid && right <= high {
		if (*arr)[left] <= (*arr)[right] {
			temp = append(temp, (*arr)[left])
			left++

		} else {
			temp = append(temp, (*arr)[right])
			right++
		}
	}

	for left <= mid {
		temp = append(temp, (*arr)[left])
		left++
	}

	for right <= high {
		temp = append(temp, (*arr)[right])
		right++
	}

	for i := 0; i < len(temp); i++ {
		(*arr)[low+i] = temp[i]
	}
}
