package array

import "math"

func FindNumAppearOnceOthersTwiceBrute(arr []int) int {
	n := len(arr)

	for i := 0; i < n-1; i++ {
		count := 1
		for j := i + 1; j < n; j++ {
			if arr[i] == arr[j] {
				count++
			}

			if count > 1 {
				break
			}
		}
		if count == 1 {
			return arr[i]
		}
	}

	return -1
}

func FindNumAppearOnceOthersTwiceHashing(arr []int) int {
	n := len(arr)
	N := arr[0]

	for i := 0; i < n; i++ {
		N = int(math.Max(float64(arr[i]), float64(N)))
	}

	hashmap := make(map[int]int, N+1)

	for i := 0; i < n; i++ {
		hashmap[arr[i]] += 1
	}

	for i := 0; i <= N; i++ {
		if hashmap[i] == 1 {
			return i
		}
	}

	return -1
}

func FindNumAppearOnceOthersTwiceOptimalXor(arr []int) int {
	xor := 0
	n := len(arr)

	for i := 0; i < n; i++ {
		xor = xor ^ arr[i]
	}

	return xor
}
