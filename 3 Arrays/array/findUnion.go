package array

func FindUnionSortedArrayUsingMap(arr1, arr2 []int) []int {
	l1 := len(arr1)
	l2 := len(arr2)

	temp := make([]int, 0, l1+l2)
	m := max(arr1[l1-1], arr2[l2-1]) + 1
	hashmap := make(map[int]int, m)

	for i := 0; i < l1; i++ {
		hashmap[arr1[i]] += 1
	}

	for j := 0; j < l2; j++ {
		hashmap[arr2[j]] += 1
	}

	for i := 0; i < m; i++ {
		if hashmap[i] > 0 {
			temp = append(temp, i)
		}
	}

	return temp
}

func FindUnionSortedArrayUsingPointers(arr1 []int, arr2 []int) []int {
	l1 := len(arr1)
	l2 := len(arr2)
	temp := make([]int, 0, l1+l2)
	t := 0
	temp = append(temp, arr1[0])

	i := 0
	j := 0

	for i < l1 && j < l2 {
		if arr1[i] < arr2[j] {
			if arr1[i] != temp[t] {
				temp = append(temp, arr1[i])
				t++
			}
			i++

		} else if arr1[i] > arr2[j] {
			if arr2[j] != temp[t] {
				temp = append(temp, arr2[j])
				t++
			}
			j++

		} else {
			if arr1[i] != temp[t] {
				temp = append(temp, arr1[i])
				t++
			}
			i++
			j++
		}

	}

	for i < l1 {
		if arr1[i] != temp[t] {
			temp = append(temp, arr1[i])
			t++
		}
		i++
	}

	for j < l2 {
		if arr2[j] != temp[t] {
			temp = append(temp, arr2[j])
			t++
		}
		j++
	}

	return temp
}
