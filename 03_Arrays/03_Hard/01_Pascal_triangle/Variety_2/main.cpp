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

vector<int> nthRow(int n) {
  vector<int> ans;

  for (int i = 0; i < n; i++) {
    ans.push_back(nCr(n-1, i));
  }

  return ans;
}