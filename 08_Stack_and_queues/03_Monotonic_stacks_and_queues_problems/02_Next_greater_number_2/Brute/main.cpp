#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

// Time :- O(N ^ 2) 
// Space :- O(1)
vector<int> nextGreaterNumber(vector<int> arr) {
  int n = arr.size();
  vector<int> ans(n, -1);

  for (int i = 0; i < n; i++) {
     int res = -1;
     int j = (i + 1) % n;

     while (j != i) {
       if (arr[j] > arr[i]) {
         res = arr[j];
         break;
       }
       j = (j + 1) % n;
     }
     ans[i] = res;
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