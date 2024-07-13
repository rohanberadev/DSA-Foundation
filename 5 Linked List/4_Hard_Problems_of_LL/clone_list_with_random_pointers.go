package hardproblemsofll

import "fmt"

type RandomNode struct {
	Data   interface{}
	Next   *RandomNode
	Random *RandomNode
}

func NewRandomNode(data interface{}, next, random *RandomNode) *RandomNode {
	return &RandomNode{Data: data, Next: next, Random: random}
}

func PrintRandomNode(head *RandomNode) {
	for node := head; node != nil; node = node.Next {
		fmt.Printf("%v -> %v\n", node, node.Random)
	}
	fmt.Print("\n")
}

// Time :- O(2 * N) Space :- O(2 * N)
func CloneRandomNode_Brute(head *RandomNode) *RandomNode {
	if head == nil {
		return nil
	}

	// Space :- O(2 * N) - Because 2 nodes are stored.
	mpp := make(map[*RandomNode]*RandomNode)
	mpp[nil] = nil

	for node := head; node != nil; node = node.Next {
		copyNode := NewRandomNode(node.Data, nil, nil)
		mpp[node] = copyNode
	}

	for node := head; node != nil; node = node.Next {
		copyNode := mpp[node]

		copyNode.Next = mpp[node.Next]
		copyNode.Random = mpp[node.Random]
	}

	return mpp[head]
}

// Time :- O(3 * N) Space :- O(N)
func CloneRandomNode_Optimal(head *RandomNode) *RandomNode {
	dummy := NewRandomNode(nil, nil, nil)
	temp := dummy
	node := head

	// Putting copy node between lists.
	for node != nil {
		copyNode := NewRandomNode(node.Data, nil, nil)
		copyNode.Next = node.Next
		node.Next = copyNode
		node = node.Next.Next
	}

	node = head

	// Pointing copy nodes's random pointers to the other copy nodes.
	for node != nil {
		copyNode := node.Next

		if node.Random != nil {
			copyNode.Random = node.Random.Next
		}

		node = node.Next.Next
	}

	node = head

	for node != nil {
		next := node.Next.Next
		copyNode := node.Next

		copyNode.Next = nil
		temp.Next = copyNode
		node.Next = next

		node = next
		temp = temp.Next
	}

	return dummy.Next
}
