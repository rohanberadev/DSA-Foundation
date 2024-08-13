#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

vector<int> find_nse(vector<int> arr, int n) {
  vector<int> nse(n);
  stack<int> st;

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    if (st.empty()) nse[i] = n;
    else nse[i] = st.top();
    st.push(i);
  }
  return nse;
}

vector<int> find_pse(vector<int> arr, int n) {
  vector<int> pse(n);
  stack<int> st;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
    if (st.empty()) pse[i] = -1;
    else pse[i] = st.top();
    st.push(i);
  }
  return pse;
}

int largestRectangleHitogram(vector<int> arr) {
  int n = arr.size();

  vector<int> pse = find_pse(arr, n);
  vector<int> nse = find_nse(arr, n);

  int maxArea = INT_MIN;

  for (int i = 0; i < n; i++) {
    int left = i - pse[i] - 1;
    int right = nse[i] - i;
    int width = left + right;

    int area = arr[i] * width;
    maxArea = max(maxArea, area);
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
