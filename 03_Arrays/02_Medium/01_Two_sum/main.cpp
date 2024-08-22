#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

// Time :- O(N ^ 2)
// Space :- O(1)
string twoSumUnsorted_brute(vector<int> arr, int target) {
  int n = arr.size();

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (arr[i] + arr[j]) return "YES";
    }
  }
  return "NO";
}

// Time :- O(N)
// Space :- O(N)
string twoSumUnsorted_hashing(vector<int> arr, int target) {
  int n = arr.size();
  map<int, int> mpp;

  for (int i = 0; i < n; i++) {
    int rem = target - arr[i];

    if (mpp.find(rem) != mpp.end()) {
      return "YES";
    }
    mpp[arr[i]] = i;
  }
  return "NO";
}

// Time :- O(N)
// Space :- O(1)
string twoSorted(vector<int> arr, int target) {
  int n = arr.size();
  int i = 0;
  int j = n-1;

  while (i < j) {
    if (arr[i] + arr[j] < target) i++;
    else if (arr[i] + arr[j] > target) j--;
    else return "YES";
  }
  return "NO";
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
  
  int n, k;
  cin >> n >> k;
  
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << twoSumUnsorted_brute(arr, k) << endl;
  cout << twoSumUnsorted_hashing(arr, k) << endl;
  sort(arr.begin(), arr.end());
  cout << twoSorted(arr, k) << endl;

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
