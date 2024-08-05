package medium

import (
	"container/list"
	"myArray/array"
)

func NextPermutationBrute(arr []int) []int {
	n := len(arr)
	num := 0

	for i := 0; i < n; i++ {
		num *= 10
		num += arr[i]
	}

	array.MergeSort(&arr, 0, n-1)

	ans := list.New()
	freq := make([]bool, n)
	nextPermList := list.New()

	Permutation(arr, list.New(), ans, freq)

	for e := ans.Front(); e != nil; e = e.Next() {
		a := e.Value.(*list.List)
		currPerm := 0
		for p := a.Front(); p != nil; p = p.Next() {
			currPerm *= 10
			currPerm += p.Value.(int)
		}

		if num < currPerm {
			nextPermList = a
			break
		}
	}

	nextPerm := make([]int, n)
	i := 0

	for e := nextPermList.Front(); e != nil; e = e.Next() {
		nextPerm[i] = e.Value.(int)
		i++
	}

	return nextPerm
}

func NextPermutationOptimal(arr []int) []int {
	n := len(arr)
	index := -1

	for i := n - 2; i >= 0; i-- {
		if arr[i] < arr[i+1] {
			index = i
			break
		}
	}

	if index == -1 {
		l := 0
		r := n - 1
		for l < r {
			temp := arr[l]
			arr[l] = arr[r]
			arr[r] = temp
			l++
			r--
		}

		return arr
	}

	for i := n - 1; i > index; i-- {
		if arr[i] > arr[index] {
			arr[i], arr[index] = arr[index], arr[i]
			break
		}
	}

	l := index + 1
	r := n - 1

	for l < r {
		arr[l], arr[r] = arr[r], arr[l]
		l++
		r--
	}

	return arr
}

func Permutation(arr []int, ds *list.List, ans *list.List, freq []bool) {
	if ds.Len() == len(arr) {
		copyList := list.New()

		for e := ds.Front(); e != nil; e = e.Next() {
			copyList.PushBack(e.Value)
		}

		ans.PushBack(copyList)
		return

	} else {
		for i := 0; i < len(arr); i++ {
			if !freq[i] {
				freq[i] = true
				ds.PushBack(arr[i])

				Permutation(arr, ds, ans, freq)

				ds.Remove(ds.Back())
				freq[i] = false
			}
		}

	}
}
