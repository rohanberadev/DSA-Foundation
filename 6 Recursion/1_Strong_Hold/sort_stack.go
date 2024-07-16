package stronghold

import ds "Recursion/DS"

func insert_at_correct_position(st *ds.Stack, data interface{}) {
	if st.Empty() || st.Peek().(int) < data.(int) {
		st.Push(data)
		return
	}

	x := st.Peek()
	st.Pop()
	insert_at_correct_position(st, data)
	st.Push(x)
}

func SortStack_Recursive(st *ds.Stack) {
	if st.Empty() {
		return
	}

	data := st.Peek()
	st.Pop()
	SortStack_Recursive(st)

	insert_at_correct_position(st, data)
}
