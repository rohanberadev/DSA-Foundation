package ds

import "fmt"

type element struct {
	data int
	next *element
}

func newElement(data int) *element {
	return &element{data: data, next: nil}
}

type Stack struct {
	first *element
	peek  *element
}

func NewStack() *Stack {
	return &Stack{first: nil, peek: nil}
}

func (st *Stack) Push(data int) {
	if st.IsEmpty() {
		st.peek = newElement(data)
		st.first = st.peek

	} else {
		newElem := newElement(data)
		st.peek.next = newElem
		st.peek = newElem
	}
}

func (st *Stack) Pop() int {
	if st.IsEmpty() {
		panic("empty stack! nothing to delete.")
	}

	if st.first.next == nil {
		delElem := st.peek
		st.peek = nil
		st.first = nil
		return delElem.data
	}

	elem := st.first
	for elem.next.next != nil {
		elem = elem.next
	}

	delElem := elem.next
	elem.next = nil
	st.peek = elem

	return delElem.data
}

func (st *Stack) Peek() int {
	if st.IsEmpty() {
		panic("empty stack! there is no peek.")
	}
	return st.peek.data
}

func (st *Stack) IsEmpty() bool {
	return st.peek == nil
}

func (st *Stack) Print() {
	for e := st.first; e != nil; e = e.next {
		fmt.Printf("%v ", e.data)
	}
	fmt.Print("\n")
}
