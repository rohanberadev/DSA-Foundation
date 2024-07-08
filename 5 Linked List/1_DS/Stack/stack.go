package stack

import (
	"fmt"
	ll "linked_list/1_DS/Singly_Linked_List"
)

type Stack struct {
	Ls *ll.LinkedList
}

func NewStack() *Stack {
	return &Stack{Ls: ll.NewEmptyList()}
}

func (st *Stack) Peek() interface{} {
	return st.Ls.Tail.Data
}

func (st *Stack) Push(data interface{}) {
	st.Ls.InsertAtBack(ll.NewNode(data, nil))
}

func (st *Stack) Pop() interface{} {
	elem := st.Ls.DeleteAtBack()
	return elem.Data
}

func (st *Stack) Print() {
	fmt.Print("[")
	for elem := st.Ls.Head; elem != nil; elem = elem.Next {
		if elem.Next == nil {
			fmt.Printf("%v", elem.Data)
		} else {
			fmt.Printf("%v ", elem.Data)
		}
	}
	fmt.Print("]")
}
