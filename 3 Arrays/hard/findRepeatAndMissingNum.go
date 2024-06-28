package hard

// Time :- O(N^2) Space :- O(1)
func FindRepeatAndMissingNumBrute(arr []int) []int {
	n := len(arr)
	ans := make([]int, 2)
	ans[0] = -1
	ans[1] = -1

	for i := 1; i <= n; i++ {
		count := 0
		for j := 0; j < n; j++ {
			if arr[j] == i {
				count++
			}
		}
		if count == 2 {
			ans[0] = i

		} else if count == 0 {
			ans[1] = i
		}

		if ans[0] != -1 && ans[1] != -1 {
			break
		}
	}

	return ans
}

// Time :- O(N) Space :- O(N)
func FindRepeatAndMissingNumHashing(arr []int) []int {
	n := len(arr)
	mpp := make([]int, n+1)
	ans := make([]int, 2)
	ans[0] = -1
	ans[1] = -1

	for i := 0; i < n; i++ {
		mpp[arr[i]] += 1
	}

	for i := 1; i <= n; i++ {
		if mpp[i] == 2 {
			ans[0] = i

		} else if mpp[i] == 0 {
			ans[1] = i
		}

		if ans[0] != -1 && ans[1] != -1 {
			break
		}
	}

	return ans
}

// Time :- O(N) Space :- O(1)
func FindRepeatAndMissingNumOptimal1(arr []int) []int {
	n := len(arr)
	ans := make([]int, 2)
	ans[0] = -1
	ans[1] = -1

	SN := n * (n + 1) / 2
	S2N := n * (n + 1) * (2*n + 1) / 6

	S := 0
	S2 := 0

	for i := 0; i < n; i++ {
		S += arr[i]
		S2 += arr[i] * arr[i]
	}

	// S - SN = x - y
	eq1 := S - SN

	if eq1 == 0 {
		return ans
	}

	// S2 - S2N = x^2 - y^2
	eq2 := S2 - S2N

	// x^2 - y^2 = (x+y) * (x-y)
	// (x+y) * (x-y) / (x-y) = x + y
	eq2 = eq2 / eq1

	x := (eq1 + eq2) / 2
	y := x - eq1

	ans[0] = x
	ans[1] = y

	return ans
}
