#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> arr) {
  int n = arr.size();
  int i = 0;
  double prefix = 1;
  double suffix = 1;

  double maxProd = INT_MIN;

  if (n == 1) return arr[0];

  while (i < n) {
    if (prefix == 0) prefix = 1;
    if (suffix == 0) suffix = 1;
    prefix *= arr[i];
    suffix *= arr[n-i-1];

    maxProd = max(maxProd, max(prefix, suffix));
    i++;
  }

  return maxProd;
}