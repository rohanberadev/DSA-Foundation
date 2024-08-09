#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

// Time :- O(4 * N)
// Space :- O(2 * N)
vector<int> nextGreaterNumber(vector<int> arr) {
  int n = arr.size();
  vector<int> ans(n, -1);
  // Worst space :- O(2 * N)
  stack<int> st;
  
  // Time :- O(2 * N)
  for (int i = 2*n-1; i >= 0; i--) {
    int ind = i % n;
    // Worst time :- O(2 * N)
    while (!st.empty() && st.top() <= arr[ind]) st.pop();

    if (st.empty()) ans[ind] = -1;
    else ans[ind] = st.top();

    st.push(arr[ind]);
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

  vector<int> ans = nextGreaterNumber(arr);
  for (auto it : ans) cout << it << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
