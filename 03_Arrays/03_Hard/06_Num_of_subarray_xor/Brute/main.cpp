#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> arr, int n, int target) {
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    int xorr = 0;
    for (int j = i; j < n; j++) {
      xorr = xorr ^ arr[j];
      if (xorr == target) cnt++;
    }
  }

  return cnt;
}