package array

// Time :- O(N^2) Space :- O(1)
func FindMissingNumberBrute(arr []int) int {
	n := len(arr)
	for i := arr[0]; i < arr[n-1]; i++ {
		found := false
		for j := 0; i < n; j++ {
			if arr[j] == i {
				found = true
				break
			}
		}

		if !found {
			return i
		}
	}

	return -1
}

// Time :- O(N) Space :- O(N)
func FindMissingNumberBetterHashing(arr []int) int {
	n := len(arr)
	N := arr[n-1]
	hashmap := make(map[int]int, N)

	for i := 0; i < n; i++ {
		hashmap[arr[i]] += 1
	}

	for i := arr[0]; i < N; i++ {
		if hashmap[i] == 0 {
			return i
		}
	}

	return -1
}

// Time :- O(N) Space :- O(1)
func FindMissingNumberOptimalSummation(arr []int) int {
	n := arr[len(arr)-1]
	sumOfN := (n * (n + 1) / 2) - ((arr[0] - 1) * (arr[0] - 1 + 1) / 2)
	sum := 0

	for i := 0; i < len(arr); i++ {
		sum += arr[i]
	}

	return sumOfN - sum
}

func FindMissingNumberOptimalXOR(arr []int) int {
	n := len(arr)
	xor1 := 0
	xor2 := 0

	for i := 0; i < n; i++ {
		xor1 = xor1 ^ arr[i]
		xor2 = xor2 ^ (i + 1)
	}

	xor2 = xor2 ^ arr[n-1]

	return (xor1 ^ xor2)
}
