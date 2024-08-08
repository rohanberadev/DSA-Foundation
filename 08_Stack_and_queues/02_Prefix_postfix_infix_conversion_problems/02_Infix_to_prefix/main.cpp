#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int getPriority(char c) {
  if (c == '^') return 3;
  else if (c == '/' || c == '*') return 2;
  else if (c == '+' || c == '-') return 1;
  else return -1;
}

void reverseString(string &s, int n) {
  int i = 0, j = n - 1;

  while (i < j) {
    char c1 = s[i], c2 = s[j];

    if (c1 == '(') c1 = ')';
    else if (c1 == ')') c1 = '(';

    if (c2 == '(') c2 = ')';
    else if (c2 == ')') c2 = '(';
    
    s[i++] = c2;
    s[j--] = c1;
  }
}

string infixToPrefix(string infix) {
  int n = infix.size();

  // resverse infix.
  reverseString(infix, n);
  
  // infix to postfix.
  string postfix = "";
  stack<char> st;

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
      if (c == '^') {
        while (!st.empty() && getPriority(c) <= getPriority(st.top())) {
          postfix += st.top();
          st.pop();
        } 
      } 
      else {
          while (!st.empty() && getPriority(c) < getPriority(st.top())) {
            postfix += st.top();
            st.pop();
        }
      }

      st.push(c);
    }
  }


  while (!st.empty()) {
    postfix += st.top();
    st.pop();
  } 
  
  // reverse postfix
  reverseString(postfix, postfix.size());
  string prefix = postfix;

  return prefix;
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
    cout << infixToPrefix(arr[i]) << endl;
  } 

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
