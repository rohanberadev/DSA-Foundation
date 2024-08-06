#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

bool isValid(string s) {
  stack<char> st;
  int n = s.size();

  for (int i = 0; i < n; i++) {
    if (!st.empty() && 
        (st.top() == '(' && s[i] == ')' || 
         st.top() == '[' && s[i] == ']' || 
         st.top() == '{' && s[i] == '}')) st.pop();

    else st.push(s[i]);
  } 

  return st.empty();
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
    if (isValid(arr[i])) cout << "Valid" << endl;
    else cout << "Not valid" << endl;
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
