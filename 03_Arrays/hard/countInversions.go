package hard

func CountInversionBrute(arr []int) int {
	n := len(arr)
	count := 0

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if arr[i] > arr[j] {
				count++
			}
		}
	}

	return count
}

func Merge(arr []int, low, mid, high int) int {
	left := low
	right := mid + 1
	cnt := 0
	temp := make([]int, 0, high-low+1)

	for left <= mid && right <= high {
		if arr[left] <= arr[right] {
			temp = append(temp, arr[left])
			left++

		} else {
			temp = append(temp, arr[right])
			cnt += mid - left + 1
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

	return cnt
}

func MergeSort(arr []int, low, high int) int {
	count := 0
	if low < high {
		mid := (low + high) / 2

		count += MergeSort(arr, low, mid)
		count += MergeSort(arr, mid+1, high)

		count += Merge(arr, low, mid, high)
	}

	return count
}

func CountInversionOptimal(arr []int) int {
	return MergeSort(arr, 0, len(arr)-1)
}
