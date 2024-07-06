package ll

import (
	"fmt"
)

type Node struct {
	Data interface{}
	Next *Node
}

type LinkedList struct {
	Head *Node
	Tail *Node
}

func NewList(node *Node) *LinkedList {
	return &LinkedList{Head: node, Tail: node}
}

func NewNode(data interface{}, next *Node) *Node {
	return &Node{Data: data, Next: next}
}

func (ls *LinkedList) IsEmpty() bool {
	return ls.Head == nil
}

// Insert At First.
func (ls *LinkedList) InsertAtFront(node *Node) {
	node.Next = ls.Head
	ls.Head = node

	if ls.Tail == nil {
		ls.Tail = node
	}
}

// Insert At Last.
func (ls *LinkedList) InsertAtBack(node *Node) {
	if ls.IsEmpty() {
		ls.Head = node
		ls.Tail = node
		return
	}

	ls.Tail.Next = node
	ls.Tail = node
}

// Delete At Fisrt.
func (ls *LinkedList) DeleteFront() *Node {
	if ls.IsEmpty() {
		fmt.Println("List is empty. Nothing to delete.")
		return NewNode(nil, nil)
	}

	head := ls.Head
	ls.Head = head.Next
	head.Next = nil

	if ls.Head == nil {
		ls.Tail = nil
	}

	return head
}

// Delete At Last.
func (ls *LinkedList) DeleteAtBack() *Node {
	if ls.IsEmpty() {
		fmt.Println("List is empty. Nothing to delete.")
		return NewNode(nil, nil)
	}

	node := ls.Head
	tail := ls.Tail

	for node.Next != ls.Tail {
		node = node.Next
	}
	node.Next = nil
	ls.Tail = node

	if ls.Tail == nil {
		ls.Head = nil
	}

	return tail
}

// Print all the values of Linked List.
func (ls *LinkedList) Print() {
	fmt.Print("[")
	for node := ls.Head; node != nil; node = node.Next {
		if node.Next == nil {
			fmt.Printf("%v", node.Data)
		} else {
			fmt.Printf("%v ", node.Data)
		}
	}
	fmt.Print("]\n")
}

// Get the length of the Linked List.
func (ls *LinkedList) Size() int {
	len := 0
	for node := ls.Head; node != nil; node = node.Next {
		len++
	}

	return len
}

// Convert Array to Linked List.
func ConvertArrayToLL(array []interface{}) *LinkedList {
	head := NewNode(array[0], nil)
	ls := NewList(head)
	ls.Head = head
	mover := head

	for i := 1; i < len(array); i++ {
		mover.Next = NewNode(array[i], nil)
		mover = mover.Next
	}

	ls.Tail = mover

	return ls
}

// Convert Linked List to Array.
func ConvertLLToArray(ls *LinkedList) []interface{} {
	array := make([]interface{}, 0, ls.Size())
	for node := ls.Head; node != nil; node = node.Next {
		array = append(array, node.Data)
	}

	return array
}

// Check if the value is present in the Linked List.
func (ls *LinkedList) IsPresent(target interface{}) bool {
	findNode := NewNode(target, nil)
	for node := ls.Head; node != nil; node = node.Next {
		if node.Data == findNode.Data {
			return true
		}
	}

	return false
}
