#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;


// Time :- O(N ^ 2)
// Space :- O(1)
int longestConsecutive(vector<int> arr) {
  int n = arr.size();
  map<int, bool> numMap;
  int len = 1;
  int maxLen = 0;

  for (int i = 0; i < n; i++) numMap[arr[i]] = true;

  for (int i = 0; i < n; i++) {
    if (numMap[arr[i]+1]) {
      len++;
      maxLen = max(maxLen, len);
      numMap[arr[i]+1] = false;
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
