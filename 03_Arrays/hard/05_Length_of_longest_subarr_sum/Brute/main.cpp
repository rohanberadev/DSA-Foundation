#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> arr, int n) {
  int maxi = 0;

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[j];
      if (sum == 0) {
        maxi = max(maxi, j-i+1);
      }
    }
  }

  return maxi;
}