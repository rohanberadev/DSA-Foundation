#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n) {
  long long SN = n * (n + 1) / 2;
  long long S2N = n * (n + 1) * (2 * n + 1) / 6;

  long long S = 0;
  long long S2 = 0;

  for (int i = 0; i < n; i++)  {
    S += arr[i];
    S2 += arr[i] * arr[i];
  }
  
  // S - SN = x - y
  long long eq1 = S - SN;

  // (S2 - S2N) / eq1 = (x^2 - y^2) / (x - y)
  // (x - y) * (x + y) / (x - y) = x + y
  long long eq2 = (S2 - S2N) / eq1;

  // ((x - y) + (x + y)) / 2 = 2x / 2
  // 2x / 2 = x
  long long x = (eq1 + eq2) / 2;

  // x - (x - y) = y
  long long y = x - eq1;

  return {int(x), int(y)};
}