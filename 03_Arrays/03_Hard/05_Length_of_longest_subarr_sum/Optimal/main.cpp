#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> arr, int n) {
  int maxi = 0;

  unordered_map<int, int> preSumMap;
  int preSum = 0;

  for (int i = 0; i < n; i++) {
    preSum += arr[i];

    if (preSum == 0) maxi = i+1;

    int rem = preSum - 0;

    if (preSumMap.find(rem) != preSumMap.end()) {
      maxi = max(maxi, i-preSumMap[rem]);
    }

    if (preSumMap.find(preSum) == preSumMap.end()) preSumMap[preSum] = i;
  }

  return maxi;
}