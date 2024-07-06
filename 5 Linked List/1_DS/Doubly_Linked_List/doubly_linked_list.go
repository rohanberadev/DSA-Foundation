package dll

import "fmt"

type Node struct {
	Data interface{}
	Prev *Node
	Next *Node
}

type DoubleLinkedList struct {
	Head *Node
	Tail *Node
}

func NewDoublyNode(data interface{}, prev *Node, next *Node) *Node {
	return &Node{Data: data, Prev: prev, Next: next}
}

func NewDoubleLinkedList(node *Node) *DoubleLinkedList {
	return &DoubleLinkedList{Head: node, Tail: node}
}

func (dls *DoubleLinkedList) IsEmpty() bool {
	return dls.Head == nil
}

func (dls *DoubleLinkedList) InsertAtFront(node *Node) {
	if dls.IsEmpty() {
		dls.Head = node
		dls.Tail = node
		return
	}

	head := dls.Head
	head.Prev = node
	node.Prev = nil
	node.Next = head
	dls.Head = node
}

func (dls *DoubleLinkedList) InsertAtBack(node *Node) {
	if dls.IsEmpty() {
		dls.Head = node
		dls.Tail = node
		return
	}

	tail := dls.Tail
	tail.Next = node
	node.Prev = tail
	dls.Tail = node
}

func (dls *DoubleLinkedList) DeleteAtFront() *Node {
	if dls.IsEmpty() {
		fmt.Println("List is empty. Nothing to delete.")
		return NewDoublyNode(nil, nil, nil)

	} else if dls.Head.Next == nil {
		head := dls.Head
		dls.Head = nil
		dls.Tail = nil
		return head
	}

	head := dls.Head
	dls.Head = head.Next
	head.Next.Prev = nil
	head.Next = nil

	return head
}

func (dls *DoubleLinkedList) DeleteAtBack() *Node {
	if dls.IsEmpty() {
		fmt.Println("List is empty. Nothing to delete.")
		return NewDoublyNode(nil, nil, nil)

	} else if dls.Tail.Prev == nil {
		tail := dls.Tail
		dls.Tail = nil
		dls.Head = nil
		return tail
	}

	tail := dls.Tail
	dls.Tail = tail.Prev
	tail.Prev.Next = nil
	tail.Prev = nil

	return tail
}

func (dls *DoubleLinkedList) Size() int {
	size := 0
	for node := dls.Head; node != nil; node = node.Next {
		size++
	}

	return size
}

func (dls *DoubleLinkedList) Print() {
	fmt.Print("[")

	for node := dls.Head; node != nil; node = node.Next {
		if node.Next == nil {
			fmt.Printf("%v", node.Data)
		} else {
			fmt.Printf("%v ", node.Data)
		}
	}

	fmt.Print("]\n")
}

func (dls *DoubleLinkedList) ReverseDLL() {
	mover := dls.Head
	var prev *Node
	var next *Node

	for mover != nil {
		next = mover.Next
		mover.Prev = mover.Next
		mover.Next = prev
		prev = mover
		mover = next
	}

	head := dls.Head
	dls.Head = prev
	dls.Tail = head
}

func ConvertArrayToDLL(array []interface{}) *DoubleLinkedList {
	head := NewDoublyNode(array[0], nil, nil)
	dls := NewDoubleLinkedList(head)

	for i := 1; i < len(array); i++ {
		node := NewDoublyNode(array[i], nil, nil)
		dls.InsertAtBack(node)
	}

	return dls
}

func ConvertDLLToArray(dls *DoubleLinkedList) []interface{} {
	array := make([]interface{}, 0, dls.Size())

	for node := dls.Head; node != nil; node = node.Next {
		array = append(array, node.Data)
	}

	return array
}
