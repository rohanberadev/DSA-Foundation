#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int minDist, int k) {
  int n = stalls.size();

  int lastStalls = stalls[0];
  int cows = 1;

  for (int i = 1; i < n; i++) {
    if (stalls[i] - lastStalls >= minDist) {
      lastStalls = stalls[i];
      cows++;
    }

    if (cows >= k) {
      return true;
    }
  }

  return false;
}

int agressiveCows(vector<int> &stalls, int k) {
  int n = stalls.size();

  sort(stalls.begin(), stalls.end());

  int low = 1, high = stalls[n - 1];

  while (low <= high) {
    int mid = (low + high) / 2;

    if (isPossible(stalls, mid, k)) {
      low = mid + 1;
    }

    else {
      high = mid - 1;
    }
  }

  return high;
}