#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
  long long ans = 1;

  for (int i = 0; i < r; i++) {
    ans = ans * (n-i);
    ans = ans / (i+1);
  }

  return ans;
}

vector<vector<int>> generatePascal(int numRows) {
  vector<vector<int>> ans;

  for (int i = 0; i < numRows; i++) {
    vector<int> arr;
    for (int j = 0; j <= i; j++) {
      arr.push_back(nCr(i, j));
    }
  }

  return ans;
}