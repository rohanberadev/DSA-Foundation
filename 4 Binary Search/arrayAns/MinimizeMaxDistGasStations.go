package arrayans

import (
	pq "github.com/emirpasic/gods/queues/priorityqueue"
	"github.com/emirpasic/gods/utils"
)

type Element struct {
	sectionLen   float64
	sectionIndex int
}

// Comparator function (sort by element's priority value in descending order)
func byPriority(a, b interface{}) int {
	elementA := a.(Element)
	elementB := b.(Element)

	if elementA.sectionLen == elementB.sectionLen {
		return -utils.IntComparator(elementA.sectionIndex, elementB.sectionIndex)
	}

	return -utils.Float64Comparator(elementA.sectionLen, elementB.sectionLen)
}

// Time :- O(K * N) Space :- O(N-1)
func MinimizeMaxDistGasStations_Brute(arr []int, k int) float64 {
	n := len(arr)
	howMany := make([]int, n-1)

	for station := 1; station <= k; station++ {
		maxVal := float64(-1)
		maxInd := -1

		for i := 0; i < n-1; i++ {
			diff := float64(arr[i+1]) - float64(arr[i])
			sectionLen := diff / (float64(howMany[i]) + 1)

			if maxVal < sectionLen {
				maxVal = sectionLen
				maxInd = i
			}
		}
		howMany[maxInd] += 1
	}

	maxAns := float64(-1)
	for i := 0; i < n-1; i++ {
		diff := float64(arr[i+1]) - float64(arr[i])
		sectionLen := diff / (float64(howMany[i]) + 1)

		if maxAns < sectionLen {
			maxAns = sectionLen
		}
	}

	return maxAns
}

// Time :- O(K * Log N) Space :- O(2(N-1))
func MinimizeMaxDistGasStations_PriorityQueue(arr []int, k int) float64 {
	n := len(arr)
	howMany := make([]int, n-1)
	priority_queue := pq.NewWith(byPriority)

	for i := 0; i < n-1; i++ {
		sectionLen := float64(arr[i+1] - arr[i])
		elem := Element{sectionLen: sectionLen, sectionIndex: i}
		priority_queue.Enqueue(elem)
	}

	for station := 1; station <= k; station++ {
		// Getting the top max value.
		tp, _ := priority_queue.Peek()
		priority_queue.Dequeue()

		// section index of the peek value.
		sectionInd := tp.(Element).sectionIndex

		howMany[sectionInd] += 1

		// intial difference.
		initialDiff := float64(arr[sectionInd+1]) - float64(arr[sectionInd])

		// new section len.
		newSectionLen := initialDiff / (float64(howMany[sectionInd]) + 1)

		priority_queue.Enqueue(Element{sectionLen: newSectionLen, sectionIndex: sectionInd})
	}

	tp, _ := priority_queue.Peek()

	return tp.(Element).sectionLen
}
