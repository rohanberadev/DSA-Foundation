package hard

// Time :- O(N^2) Space :- O(1)
func MajorityNDivides3Brute(arr []int) int {
	n := len(arr)

	for i := 0; i < n-1; i++ {
		cand := arr[i]

		if cand == -1 {
			continue
		}

		count := 1
		arr[i] = -1

		for j := i + 1; j < n; j++ {
			if cand == arr[j] {
				arr[j] = -1
				count++
			}
		}

		if count > n/3 {
			return cand
		}

	}

	return -1
}

func MajorityNDivides3Hashing(arr []int) int {
	n := len(arr)
	numMap := make(map[int]int)

	for i := 0; i < n; i++ {
		numMap[arr[i]] += 1
	}

	for key, val := range numMap {
		if val > n/3 {
			return key
		}
	}

	return -1
}

func MajorityNDivides3Optimal(arr []int) []int {
	ans := make([]int, 2)
	n := len(arr)
	elem1 := -1
	elem2 := -1

	count1 := 0
	count2 := 0

	for i := 0; i < n; i++ {
		if count1 == 0 && elem2 != arr[i] {
			elem1 = arr[i]
			count1 = 1

		} else if count2 == 0 && elem1 != arr[i] {
			elem2 = arr[i]
			count2 = 1

		} else if arr[i] == elem1 {
			count1++

		} else if arr[i] == elem2 {
			count1++

		} else {
			count1--
			count2--
		}
	}

	count1, count2 = 0, 0

	for i := 0; i < n; i++ {
		if elem1 == arr[i] {
			count1++

		} else if elem2 == arr[i] {
			count2++
		}
	}

	mini := n/3 + 1
	if count1 >= mini {
		ans = append(ans, elem1)
	}

	if count2 >= mini {
		ans = append(ans, elem2)
	}

	return ans
}
