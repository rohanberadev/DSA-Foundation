package ds

import "fmt"

type stackframe struct {
	data interface{}
	next *stackframe
}

func newStackFrame(data interface{}) *stackframe {
	return &stackframe{data: data, next: nil}
}

type Stack struct {
	root *stackframe
	top  *stackframe
	size int
}

func NewStack() *Stack {
	return &Stack{root: nil, top: nil, size: 0}
}

func (st *Stack) Empty() bool {
	return st.top == nil
}

func (st *Stack) Size() int {
	return st.size
}

func (st *Stack) Push(data interface{}) {
	st.size++
	if st.Empty() {
		st.top = newStackFrame(data)
		st.root = st.top
		return
	}

	st.top.next = newStackFrame(data)
	st.top = st.top.next
}

func (st *Stack) Pop() interface{} {
	if st.Empty() {
		fmt.Println("Stack is Empty.")
		return nil
	}

	st.size--

	if st.root.next == nil {
		data := st.top.data
		st.top = nil
		st.root = nil
		return data
	}

	sf := st.root
	for sf.next != st.top {
		sf = sf.next
	}

	data := st.top.data
	sf.next = nil
	st.top = sf

	return data
}

func (st *Stack) Peek() interface{} {
	return st.top.data
}

func (st *Stack) Reverse() {
	sf := st.root
	var prev *stackframe

	for sf != nil {
		next := sf.next
		sf.next = prev
		prev = sf
		sf = next
	}

	st.top = st.root
	st.root = prev
}

func (st *Stack) Print() {
	for sf := st.root; sf != nil; sf = sf.next {
		fmt.Printf("%v ", sf.data)
	}
	fmt.Print("\n")
}
