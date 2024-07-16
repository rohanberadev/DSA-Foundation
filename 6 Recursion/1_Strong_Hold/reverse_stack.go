package stronghold

import ds "Recursion/DS"

func ReverseStack_Recursive_Brute(st, ans *ds.Stack) {
	if st.Empty() {
		return
	}

	ans.Push(st.Peek())
	st.Pop()
	ReverseStack_Recursive_Brute(st, ans)
}

func insert_at_bottom(st *ds.Stack, data interface{}) {
	if st.Empty() {
		st.Push(data)
		return
	}

	x := st.Peek()
	st.Pop()
	insert_at_bottom(st, data)
	st.Push(x)
}

func ReverseStack_Recursive_Optimal(st *ds.Stack) {
	if st.Empty() {
		return
	}

	data := st.Peek()
	st.Pop()
	ReverseStack_Recursive_Optimal(st)

	insert_at_bottom(st, data)
}
