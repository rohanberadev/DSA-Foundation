package arrayans

import "math"

// Time :- O(M + N) Space :- (M + N)
func MedianOf2SortedArray_Brute(arr1, arr2 []int) float64 {
	m := len(arr1)
	n := len(arr2)
	temp := make([]int, 0, m+n)

	left := 0
	right := 0

	for left < m && right < n {
		if arr1[left] <= arr2[right] {
			temp = append(temp, arr1[left])
			left++

		} else {
			temp = append(temp, arr2[right])
			right++
		}
	}

	for left < m {
		temp = append(temp, arr1[left])
		left++
	}

	for right < n {
		temp = append(temp, arr2[right])
		right++
	}

	if (m+n)%2 == 0 {
		median := (float64(temp[(m+n)/2]) + float64(temp[((m+n)/2)-1])) / 2.0
		return median
	}

	return float64(temp[(m+n)/2])
}

// Time :- O(N1 + N2) Space :- O(1)
func MedianOf2SortedArray_Better(arr1, arr2 []int) float64 {
	n1 := len(arr1)
	n2 := len(arr2)

	// total length.
	n := n1 + n2

	// middle 2 elements index.
	ind2 := n / 2
	ind1 := n/2 - 1

	ind1Elem := -1
	ind2Elem := -1

	left := 0
	right := 0
	cnt := 0

	for left < n1 && right < n2 {
		if arr1[left] <= arr2[right] {
			if cnt == ind1 {
				ind1Elem = arr1[left]
			}
			if cnt == ind2 {
				ind2Elem = arr1[left]
			}
			left++
			cnt++

		} else {
			if cnt == ind1 {
				ind1Elem = arr2[right]
			}
			if cnt == ind2 {
				ind2Elem = arr2[right]
			}
			right++
			cnt++
		}
	}

	if n%2 == 0 {
		return float64(ind1Elem+ind2Elem) / 2.0
	}

	return float64(ind2Elem)
}

func MedianOf2SortedArray_Optimal(a, b []int) float64 {
	n1 := len(a)
	n2 := len(b)

	if n1 > n2 {
		return MedianOf2SortedArray_Optimal(b, a)
	}

	n := n1 + n2
	low := 0
	high := n1

	left := (n1 + n2 + 1) / 2

	for low <= high {
		mid1 := (low + high) / 2
		mid2 := left - mid1

		l1 := math.MinInt64
		l2 := math.MinInt64
		r1 := math.MaxInt64
		r2 := math.MaxInt64

		if mid1 < n1 {
			r1 = a[mid1]
		}
		if mid2 < n2 {
			r2 = b[mid2]
		}
		if mid1-1 >= 0 {
			l1 = a[mid1-1]
		}
		if mid2-1 >= 0 {
			l2 = b[mid2-1]
		}

		if l1 <= r2 && l2 <= r1 {
			if n%2 == 1 {
				median := math.Max(float64(l1), float64(l2))
				return median

			} else {
				median := (math.Max(float64(l1), float64(l2)) + math.Min(float64(r1), float64(r2))) / 2
				return median
			}

		} else if l1 > r2 {
			high = mid1 - 1

		} else if l2 > r1 {
			low = mid1 + 1
		}

	}

	return 0.0
}
