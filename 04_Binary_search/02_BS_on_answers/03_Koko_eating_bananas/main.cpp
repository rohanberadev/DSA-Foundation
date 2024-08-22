#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &piles, int speed, int h) {
  int n = piles.size();
  long long int totalTime = 0;

  for (int i = 0; i < n; i++) {
    totalTime += ceil(double(piles[i]) / double(speed));

    if (totalTime > h) {
      return false;
    }
  }

  if (totalTime <= h) {
    return true;
  }

  return false;
}

int findMax(vector<int> &piles, int n) {
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, piles[i]);
  }

  return maxi;
}

int minEatingSpeed(vector<int> &piles, int h) {
  int n = piles.size();

  int low = 1, high = findMax(piles, n);

  while (low <= high) {
    int mid = (low + high) / 2;

    if (isPossible(piles, mid, h)) {
      high = mid - 1;
    }

    else {
      low = mid + 1;
    }
  }

  return low;
}