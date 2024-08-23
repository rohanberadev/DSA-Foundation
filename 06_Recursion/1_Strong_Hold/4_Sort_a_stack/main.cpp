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
  if (st.empty())
    return;

  int x = st.top();
  st.pop();
  sortStack(st);
  insertAtCorrectPos(st, x);
}

// Link -
// https://bit.ly/3Pu0YBn