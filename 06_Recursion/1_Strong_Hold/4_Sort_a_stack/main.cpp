#include <bits/stdc++.h>
using namespace std;

void insertAtCorrectPos(stack<int> &st, int data) {
	if (st.empty() || st.top() <= data) {
		st.push(data);
		return;
	}

	int x = st.top();
	st.pop();
	insertAtCorrectPos(st, data);
	st.push(x);
}

// Time :- O(N^2)
void sortStack(stack<int> &st) {
	if (st.empty()) return;

	int x = st.top();
	st.pop();
	sortStack(st);
	insertAtCorrectPos(st, x);
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

	sortStack(st);

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}