package arrayans

import "math"

// Time :- O(M + N) Space :- O(M + N)
func KthElementOf2SortedArray_Brute(a, b []int, k int) int {
	n1 := len(a)
	n2 := len(b)

	if n1+n2 < k {
		return -1
	}

	temp := make([]int, 0, n1+n2)

	i := 0
	j := 0

	for i < n1 && j < n2 {
		if a[i] <= b[j] {
			temp = append(temp, a[i])
			i++
		} else {
			temp = append(temp, b[j])
			j++
		}
	}

	for i < n1 {
		temp = append(temp, a[i])
		i++
	}

	for j < n2 {
		temp = append(temp, b[j])
		j++
	}

	return temp[k-1]
}

// Time :- O(M + N) Space :- O(1)
func KthElementOf2SortedArray_Better(a, b []int, k int) int {
	n1 := len(a)
	n2 := len(b)

	if n1+n2 < k {
		return -1
	}

	i := 0
	j := 0

	cnt := 0
	elem := -1
	for i < n1 && j < n2 {
		if cnt == k {
			break
		}
		if a[i] <= b[j] {
			elem = a[i]
			i++
			cnt++
		} else {
			elem = b[j]
			j++
			cnt++
		}
	}

	return elem
}

// Time :- O(Log (min(k, n1) - max(0, k-n2))) Space :- O(1)
func KthElementOf2SortedArray_Optimal(a, b []int, k int) int {
	n1 := len(a)
	n2 := len(b)

	if n1+n2 < k {
		return -1
	}

	if n1 > n2 {
		return KthElementOf2SortedArray_Optimal(b, a, k)
	}

	left := k
	low := int(math.Max(0, float64(k-n2)))
	high := int(math.Min(float64(k), float64(n1)))

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
		if mid1 < n2 {
			r2 = b[mid2]
		}
		if mid1-1 >= 0 {
			l1 = a[mid1-1]
		}
		if mid2-1 >= 0 {
			l2 = b[mid2-1]
		}

		if l1 <= r2 && l2 <= r1 {
			elem := int(math.Max(float64(l1), float64(l2)))
			return elem

		} else if l1 > r2 {
			high = mid1 - 1

		} else {
			low = mid1 + 1
		}
	}

	return -1
}
