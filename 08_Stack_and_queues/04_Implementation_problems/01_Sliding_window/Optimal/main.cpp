#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
  int n = arr.size();
  vector<int> maxNums;
  deque<int> dq;

  for (int i = 0; i < n; i++) {
    if (!dq.empty() && dq.front() <= i-k && i > k-1) dq.pop_front();

    while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
    dq.push_back(i);

    if (i >= k-1) maxNums.push_back(arr[dq.front()]); 
  }

  return maxNums;
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

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

  vector<int> maxSums = maxSlidingWindow(arr, k);
  for (auto it : maxSums) cout << it << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}