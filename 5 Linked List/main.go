package main

import (
	"fmt"
	ds "linked_list/1_DS"
)

func main() {
	arr := []interface{}{2, 4, 8, 10}
	ls := ds.ConvertArrayToLL(arr)
	ls.Print()
	ls.InsertAtFront(*ds.NewNode(11, nil))
	ls.Print()
	fmt.Println(ls.DeleteFront())
	ls.Print()
}
