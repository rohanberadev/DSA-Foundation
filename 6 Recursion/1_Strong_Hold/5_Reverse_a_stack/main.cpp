#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int data) {
	if (st.empty()) {
		st.push(data);
		return;
	}

	int x = st.top();
	st.pop();
	insertAtBottom(st, data);
	st.push(x);
}

void reverseStack(stack<int> &st) {
	if (st.empty()) return;

	int x = st.top();
	st.pop();
	reverseStack(st);
	insertAtBottom(st, x);
}

int main() {
	int size;
	cin >> size;

	stack<int> st;
	for (int i = 0; i < size; i++) {
		int data;
		cin >> data;
		st.push(data);
	}

	reverseStack(st);

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}