#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> arr, int target) {
  int n = arr.size();
  int low = 0, high = n - 1;
  int ind = n;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] >= target) {
      ind = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ind;
}

// Link -
// https: // leetcode.com/problems/search-insert-position/