#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

vector<int> previousSmallerNumber(vector<int> arr) {
  int n = arr.size();
  vector<int> ans(n);
  stack<int> st;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && st.top() >= arr[i]) st.pop();

    if (st.empty()) ans[i] = -1;
    else ans[i] = st.top();

    st.push(arr[i]);
  }

  return ans;
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
  
  int size;
  cin >> size;
  
  vector<int> arr(size);
  for (int i = 0; i < size; i++) cin >> arr[i];

  vector<int> ans = previousSmallerNumber(arr);
  for (auto it : ans) cout << it << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
