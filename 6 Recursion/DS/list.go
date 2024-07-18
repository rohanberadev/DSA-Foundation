package ds

import (
	"fmt"
)

type node struct {
	data interface{}
	next *node
}

func NewNode(data interface{}) *node {
	return &node{data: data, next: nil}
}

type List struct {
	root *node
	tail *node
}

func NewList() *List {
	return &List{root: nil, tail: nil}
}

func (ls *List) Empty() bool {
	return ls.root == nil
}

func (ls *List) Push_back(data interface{}) *node {
	if ls.Empty() {
		ls.root = NewNode(data)
		ls.tail = ls.root
		return ls.root
	}

	ls.tail.next = NewNode(data)
	ls.tail = ls.tail.next
	return ls.tail
}

func (ls *List) Pop_Back() interface{} {
	if ls.Empty() {
		panic("list is empty.")
	}

	if ls.root.next == nil {
		delNode := ls.root
		ls.root = ls.root.next
		return delNode.data
	}

	mover := ls.root

	for mover.next != ls.tail {
		mover = mover.next
	}

	delNode := ls.tail
	ls.tail = mover
	ls.tail.next = nil

	return delNode.data
}

func (ls *List) Print() {
	fmt.Print("[")
	for node := ls.root; node != nil; node = node.next {
		if node.next == nil {
			fmt.Printf("%v", node.data)
		} else {
			fmt.Printf("%v ", node.data)
		}
	}
	fmt.Print("]\n")
}
