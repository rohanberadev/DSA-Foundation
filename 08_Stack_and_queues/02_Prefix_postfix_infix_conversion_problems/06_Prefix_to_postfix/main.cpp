#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

string prefixToPostfix(string prefix) {
  int n = prefix.size();
  stack<string> st;

  for (int i = n-1; i >= 0; i--) {
    char c = prefix[i];

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) st.push(string(1, c));

    else {
      string first = st.top();
      st.pop();
      string second = st.top();
      st.pop();

      string ans = first + second + c;
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
  for (int i = 0; i < n; i++) cin >> arr[i];

  for (int i = 0; i < n; i++) cout << prefixToPostfix(arr[i]);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
