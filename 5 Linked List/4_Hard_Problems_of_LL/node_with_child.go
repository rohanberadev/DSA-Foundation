package hardproblemsofll

import "fmt"

type NodeWithChild struct {
	Data  interface{}
	Next  *NodeWithChild
	Child *NodeWithChild
}

func NewNodeWithChild(data interface{}, next, child *NodeWithChild) *NodeWithChild {
	return &NodeWithChild{Data: data, Next: next, Child: child}
}

func PrintNodeWithChild(head *NodeWithChild) {
	for node := head; node != nil; node = node.Child {
		fmt.Printf("%v ", node.Data)
	}
	fmt.Print("\n")
}
