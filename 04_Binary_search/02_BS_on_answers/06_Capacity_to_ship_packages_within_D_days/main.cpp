#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &weights, int maxWeight, int days) {
  int n = weights.size();

  long long load = 0;
  int d = 1;

  for (int i = 0; i < n; i++) {
    if (d > days) {
      return false;
    }

    if (load + weights[i] <= maxWeight) {
      load += weights[i];
    }

    else {
      load = weights[i];
      d++;
    }
  }

  if (d <= days) {
    return true;
  }

  return false;
}

long long summation(vector<int> &arr, int n) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  return sum;
}

int findMax(vector<int> &arr, int n) {
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, arr[i]);
  }

  return maxi;
}

int shipWithinDays(vector<int> &weights, int days) {
  int n = weights.size();

  long long low = findMax(weights, n), high = summation(weights, n);

  while (low <= high) {
    int mid = (low + high) / 2;

    if (isPossible(weights, mid, days)) {
      high = mid - 1;
    }

    else {
      low = mid + 1;
    }
  }

  return low;
}