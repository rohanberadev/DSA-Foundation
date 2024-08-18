#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> arr) {
  int n = arr.size();
  int maxPro = 0;

  if (n == 1) return arr[0];

  for (int i = 0; i < n; i++) {
    int product = 1;
    for (int j = i; j < n; j++) {
      product *= arr[j];
      if (product == 0) break;
      maxPro = max(maxPro, product);
    }
  }

  return maxPro;
}