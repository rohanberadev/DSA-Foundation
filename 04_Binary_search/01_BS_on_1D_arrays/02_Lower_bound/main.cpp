#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int target) {
  int n = arr.size();

  int low = 0, high = n - 1;
  int ind = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] <= target) {
      ind = mid;
      low = mid + 1;
    } else if (arr[mid] > target) {
      high = mid - 1;
    }
  }

  return ind;
}

// Link -
// https://bit.ly/3Cf398N