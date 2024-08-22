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