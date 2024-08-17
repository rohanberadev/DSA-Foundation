#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

// Time :- O((N * Log(N) + N)
// Space :- O(1)
int longestConsecutive(vector<int> arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());

  int len = 1;
  int maxLen = 0;

  for (int i = 0; i < n-1; i++) {
    if (arr[i]+1 == arr[i+1]) {
      len++;
      maxLen = max(maxLen, len);
    }
    else len = 1;
  }

  return maxLen;
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
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  cout << longestConsecutive(arr);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
