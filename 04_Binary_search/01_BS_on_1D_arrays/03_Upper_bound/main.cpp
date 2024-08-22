#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> arr, int target) {
  int n = arr.size();

  int low = 0, high = n - 1;
  int ind = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] >= target) {
      ind = mid;
      high = mid - 1;
    } else if (arr[mid] < target) {
      low = mid + 1;
    }
  }

  return ind;
}