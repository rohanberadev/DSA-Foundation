#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int getPriority(char op) {
  if (op == '^') return 3;
  else if (op == '*' || op == '/') return 2;
  else if (op == '+' || op == '-') return 1;
  else return -1;
}

string infixToPostfix(string infix) {
  int n = infix.size();
  stack<char> st;
  
  string postfix = "";

  for (int i = 0; i < n; i++) {
    char c = infix[i];

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) postfix += c;

    else if (c == '(') st.push(c);

    else if (c == ')') {
      while (st.top() != '(') {
        postfix += st.top();
        st.pop();
      }

      st.pop();
    }

    else {
      while (!st.empty() && getPriority(c) <= getPriority(st.top())) {
        postfix += st.top();
        st.pop();
      }

      st.push(c);
    }
    
  }

  while (!st.empty()) {
    postfix += st.top();
    st.pop();
  }
    
  return postfix;
}

int main() {
  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input file.";
    return 1;
  } 

  streambuf* cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());

  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output file.";
    return 1;
  }
  
  streambuf* coutbuf = cout.rdbuf();
  cout.rdbuf(outfile.rdbuf());
  
  int n;
  cin >> n;
  
  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    cout << infixToPostfix(arr[i]) << endl;
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
