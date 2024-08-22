#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr) {
  int n = arr.size();

  int low = 0, high = n - 1;
  int mini = INT_MAX;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[low] <= arr[high]) {
      mini = min(mini, arr[low]);
      break;
    }

    if (arr[low] <= arr[mid]) {
      mini = min(mini, arr[low]);
      low = mid + 1;
    }

    else if (arr[mid] <= arr[high]) {
      mini = min(mini, arr[mid]);
      high = mid - 1;
    }
  }

  return mini;
}