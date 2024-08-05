package hard

import (
	"fmt"
	"slices"
)

// Time :- (m*n + N Log N) Space :- O(1)
func Merge2SortedArrayWithoutExtraSpaceMySelf(arr1, arr2 []int) {
	m := len(arr1)
	n := len(arr2)

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if arr1[i] > arr2[j] {
				temp := arr1[i]
				arr1[i] = arr2[j]
				arr2[j] = temp
			}
		}
	}

	slices.Sort(arr2)

	fmt.Printf("arr1 -> %v\n", arr1)
	fmt.Printf("arr2 -> %v\n", arr2)
}

func Merge2SortedArrayWithoutExtraSpaceOptimal1(arr1, arr2 []int) {
	m := len(arr1)
	n := len(arr2)

	left := m - 1
	right := 0

	for left >= 0 && right < n {
		if arr1[left] > arr2[right] {
			temp := arr1[left]
			arr1[left] = arr2[right]
			arr2[right] = temp
			left--
			right++

		} else {
			break
		}
	}

	slices.Sort(arr1)
	slices.Sort(arr2)

	fmt.Printf("arr1 -> %v\n", arr1)
	fmt.Printf("arr2 -> %v\n", arr2)
}

func SwapIfGreater(arr1, arr2 *[]int, ind1, ind2 int) {
	if (*arr1)[ind1] > (*arr2)[ind2] {
		temp := (*arr1)[ind1]
		(*arr1)[ind1] = (*arr2)[ind2]
		(*arr2)[ind2] = temp
	}
}

// Time :- O((M + N) * Log2(M + N)) Space :- O(1)
func Merge2SortedArrayWithoutExtraSpaceOptimal2(arr1, arr2 []int) {
	m := len(arr1)
	l := len(arr1) + len(arr2)

	// if l is odd then it will plus one to ciel it.
	gap := (l / 2) + (l % 2)

	for gap > 0 {
		left := 0
		right := left + gap

		for right < l {

			if left < m && right >= m { // arr1 and arr2
				SwapIfGreater(&arr1, &arr2, left, right-m)

			} else if left >= m { // arr2 and arr2
				SwapIfGreater(&arr2, &arr2, left-m, right-m)

			} else { // arr1 and arr1
				SwapIfGreater(&arr1, &arr1, left, right)
			}
			left++
			right++
		}
		if gap == 1 {
			break
		}
		gap = (gap / 2) + (gap % 2)
	}

	fmt.Printf("arr1 -> %v\n", arr1)
	fmt.Printf("arr2 -> %v\n", arr2)
}
