package array1d

// Time :- O(N^2) Space :- O(1)
func FindElemAppearOnceSortedArrayBrute(arr []int) int {
	n := len(arr)

	for i := 0; i < n; i++ {
		count := 0
		for j := 0; j < n; j++ {
			if arr[i] == arr[j] {
				count++
			}
		}
		if count < 2 {
			return arr[i]
		}
	}

	return 0
}

// Time :- O(N) Space :- O(N)
func FindElemAppearOnceSortedArrayHashing(arr []int) int {
	n := len(arr)
	mpp := make(map[int]int)

	for i := 0; i < n; i++ {
		mpp[arr[i]] += 1
	}

	for k, v := range mpp {
		if v == 1 {
			return k
		}
	}

	return 0
}

// Time :- O(N) Space :- O(1)
func FindElemAppearOnceSortedArrayXOR(arr []int) int {
	n := len(arr)
	xor := 0

	for i := 0; i < n; i++ {
		xor = xor ^ arr[i]
	}

	return xor
}

func FindElemAppearOnceSortedArrayOptimal(arr []int) int {
	n := len(arr)
	if arr[0] != arr[1] {
		return arr[0]
	}

	if arr[n-1] != arr[n-2] {
		return arr[n-1]
	}

	low := 1
	high := n - 2

	for low <= high {
		mid := (low + high) / 2

		if arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1] {
			return arr[mid]
		}

		if (mid%2 == 0 && arr[mid] == arr[mid+1]) ||
			(mid%2 != 0 && arr[mid] == arr[mid-1]) {

			// eleiminate left half.
			low = mid + 1

		} else if (mid%2 != 0 && arr[mid] == arr[mid+1]) ||
			(mid%2 == 0 && arr[mid] == arr[mid-1]) {

			// eliminate right half.
			high = mid - 1
		}

	}

	return 0
}
