package hard

// Time :- O(N^2) Space:- O(1)
func ReversePairsBrute(arr []int) int {
	n := len(arr)
	count := 0

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if arr[i] > 2*arr[j] {
				count++
			}
		}
	}

	return count
}

func Merge1(arr []int, low, mid, high int) {
	left := low
	right := mid + 1
	temp := make([]int, 0, high-low+1)

	for left <= mid && right <= high {
		if arr[left] <= arr[right] {
			temp = append(temp, arr[left])
			left++

		} else {
			temp = append(temp, arr[right])
			right++
		}
	}

	for left <= mid {
		temp = append(temp, arr[left])
		left++
	}

	for right <= high {
		temp = append(temp, arr[right])
		right++
	}

	for i := low; i <= high; i++ {
		arr[i] = temp[i-low]
	}

}

func CountPairs(arr []int, low, mid, high int) int {
	right := mid + 1
	cnt := 0

	for i := low; i <= mid; i++ {
		for right <= high && arr[i] > 2*arr[right] {
			right++
		}

		cnt += right - (mid + 1)
	}

	return cnt
}

func MergeSort1(arr []int, low, high int) int {
	count := 0
	if low < high {
		mid := (low + high) / 2

		count += MergeSort(arr, low, mid)
		count += MergeSort(arr, mid+1, high)

		Merge1(arr, low, mid, high)
	}

	return count
}

// Time :- O(N Log N) Space:- O(1)
func ReversePairsOptimal(arr []int) int {
	return MergeSort1(arr, 0, len(arr)-1)
}
