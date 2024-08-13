#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int largestRectangleHitogram(vector<int> arr) {
  int n = arr.size();

  stack<int> st;

  int maxArea = 0;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      int ind = st.top();
      st.pop();
      
      int pse = st.empty() ? -1 : st.top();
      int nse = i;

      int left = ind - pse;
      int right = nse - ind;

      int width = left + right - 1;
      maxArea = max(maxArea, arr[ind] * width);
    }
    st.push(i);
  }

  while (!st.empty()) {
    int ind = st.top();
    st.pop();
    int nse = n;
    int pse = st.empty() ? -1 : st.top();

    int left = ind - pse;
    int right = nse - ind;

    int width = left + right - 1;
    maxArea = max(maxArea, arr[ind] * width); 
  }

  return maxArea;
}

int main() {
  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input file.";
    return 1;
  }

  streambuf *cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());

  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output file.";
    return 1;
  }

  streambuf *coutbuf = cout.rdbuf();
  cout.rdbuf(outfile.rdbuf());


  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << largestRectangleHitogram(arr); 

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
