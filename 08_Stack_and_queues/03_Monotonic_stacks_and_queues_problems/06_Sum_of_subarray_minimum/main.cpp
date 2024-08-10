#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

const int mod = 1e9 + 7;

int sumOfMinimumSubArray_brute(vector<int> arr) {
  int n = arr.size();
  int sum = 0;

  for (int i = 0; i < n; i++) {
    int mini = arr[i];
    for (int j = i; j < n; j++) {
      mini = min(mini, arr[j]);
      sum = (long(sum) + mini) % mod;
    }
  }
  return sum;
}

vector<int> findNSE(vector<int> arr, int n) {
  stack<int> st;
  vector<int> nse(n);

  for (int i = n-1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    if (st.empty()) nse[i] = n;
    else nse[i] = st.top();
    st.push(i);
  }
  return nse;
}

vector<int> findPSE(vector<int> arr, int n) {
  stack<int> st;
  vector<int> pse(n);

  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
    if (st.empty()) pse[i] = -1;
    else pse[i] = st.top();

    st.push(i);
  }
  return pse;
}

int sumOfMinimumSubArray(vector<int> arr) {
  int n = arr.size();
  int sum = 0;

  vector<int> nse = findNSE(arr, n);
  vector<int> pse = findPSE(arr, n);

  for (int i = 0; i < n; i++) {
    int left = i - pse[i];
    int right = nse[i] - i;

    sum = (long(sum) + (long(left) * long(right) * long(arr[i]))) % mod;
  }
  return sum;
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

  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << sumOfMinimumSubArray(arr);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
