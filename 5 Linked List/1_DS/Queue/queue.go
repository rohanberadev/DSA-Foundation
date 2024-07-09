package queue

import (
	"fmt"
	ll "linked_list/1_DS/Singly_Linked_List"
)

type Queue struct {
	Ls *ll.LinkedList
}

func NewQueue() *Queue {
	return &Queue{ll.NewEmptyList()}
}

func (q *Queue) Enqueue(data interface{}) {
	q.Ls.InsertAtBack(ll.NewNode(data, nil))
}

func (q *Queue) Dequeue() interface{} {
	data := q.Ls.DeleteAtFront().Data
	return data
}

func (q *Queue) Peek() interface{} {
	return q.Ls.Head.Data
}

func (q *Queue) IsEmpty() bool {
	return q.Ls.IsEmpty()
}

func (q *Queue) Size() int {
	return q.Ls.Size()
}

func (q *Queue) Clear() {
	for elem := q.Ls.Head; elem != nil; elem = elem.Next {
		q.Ls.DeleteAtFront()
	}
}

func (q *Queue) Contains(data interface{}) bool {
	return q.Ls.IsPresent(data)
}

func (q *Queue) Print() {
	fmt.Print("[")
	for elem := q.Ls.Head; elem != nil; elem = elem.Next {
		if elem.Next == nil {
			fmt.Printf("%v", elem.Data)
		} else {
			fmt.Printf("%v ", elem.Data)
		}
	}
	fmt.Print("]")
}
