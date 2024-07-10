package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func Size(l *ListNode) int {
	len := 1
	n := l
	for n != nil {
		n = n.Next
		len++
	}

	return len
}

func Reverse(l *ListNode) *ListNode {
	mover := l
	var prev *ListNode

	for mover != nil {
		next := mover.Next
		mover.Next = prev
		prev = mover
		mover = next
	}

	return prev
}

func AddNumToLL(node, limit *ListNode, num int) (*ListNode, int) {
	if node == nil {
		return node, 0
	}
	if node == limit {
		sum := node.Val + num
		if sum > 9 {
			n := sum % 10
			c := sum / 10
			node.Val = n
			return node, c

		} else {
			node.Val = sum
			return node, 0
		}
	}

	_, carry := AddNumToLL(node.Next, limit, num)
	sum := node.Val + carry

	if sum > 9 {
		n := sum % 10
		c := sum / 10
		node.Val = n
		return node, c

	} else {
		node.Val = sum
		return node, 0
	}
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	len1 := Size(l1)
	len2 := Size(l2)

	if len1 > len2 {
		return addTwoNumbers(l2, l1)
	}

	l1 = Reverse(l1)

	var limit *ListNode

	for n1 := l1; n1 != nil; n1 = n1.Next {
		n2 := l2
		var prev *ListNode

		for n2 != limit {
			prev = n2
			n2 = n2.Next
		}

		n2 = l2
		limit = prev

		node, carry := AddNumToLL(n2, limit, n1.Val)
		l2 = node

		if carry > 0 {
			newHead := &ListNode{Val: carry, Next: l2}
			l2 = newHead
		}
	}

	// l2 = Reverse(l2)

	return l2
}

func PrintList(head *ListNode) {
	for node := head; node != nil; node = node.Next {
		fmt.Printf("%v ", node.Val)
	}
	fmt.Print("\n")
}

func main() {
	l1 := &ListNode{Val: 2, Next: nil}
	l1.Next = &ListNode{Val: 4, Next: nil}
	l1.Next.Next = &ListNode{Val: 3, Next: nil}

	l2 := &ListNode{Val: 5, Next: nil}
	l2.Next = &ListNode{Val: 6, Next: nil}
	l2.Next.Next = &ListNode{Val: 4, Next: nil}

	PrintList(addTwoNumbers(l1, l2))
}
