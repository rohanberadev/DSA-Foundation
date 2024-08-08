#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

// Time :- O(N) Space :- O(1)
string postfixToInfix(string postfix) {
  int n = postfix.size();
  stack<string> st;


  for (int i = 0; i < n; i++) {
    char c = postfix[i];

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) st.push(string(1, c));
    
    else {
      string second = st.top();
      st.pop();
      string first = st.top();
      st.pop();
      
      // Addition of strings might take time for some lang it is O(N1 + N2)
      string ans = '(' + first + c + second + ')';
      st.push(ans);
    }
  }
  
  return st.top();
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
    cout << postfixToInfix(arr[i]);
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
