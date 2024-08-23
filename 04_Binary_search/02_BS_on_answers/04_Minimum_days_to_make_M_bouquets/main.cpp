#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &bloomDay, int m, int k, int maxDay) {
  int n = bloomDay.size();
  int bouquets = 0;
  int flowers = 0;

  for (int i = 0; i < n; i++) {
    if (bouquets == m) {
      return true;
    }

    if (bloomDay[i] <= maxDay) {
      flowers++;
      if (flowers == k) {
        bouquets++;
        flowers = 0;
      }
    }

    else {
      flowers = 0;
    }
  }

  if (bouquets >= m) {
    return true;
  }

  return false;
}

int findMax(vector<int> &arr, int n) {
  int maxi = INT_MIN;

  for (int i = 0; i < n; i++) {
    maxi = max(maxi, arr[i]);
  }

  return maxi;
}

int minDays(vector<int> &bloomDay, int m, int k) {
  int n = bloomDay.size();

  int low = 1, high = findMax(bloomDay, n);
  int ans = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (isPossible(bloomDay, m, k, mid)) {
      ans = mid;
      high = mid - 1;
    }

    else {
      low = mid + 1;
    }
  }

  return ans;
}

// Link -
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/