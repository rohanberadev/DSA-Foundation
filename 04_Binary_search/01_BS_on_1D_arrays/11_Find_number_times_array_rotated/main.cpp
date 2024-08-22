#include <bits/stdc++.h>
using namespace std;

int findRotation(vector<int> &arr) {
  int n = arr.size();

  int low = 0, high = n - 1;
  int ind = -1, mini = INT_MAX;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[low] <= arr[high]) {
      if (arr[low] <= mini) {
        mini = arr[low];
        ind = low;
      }
      break;
    }

    if (arr[low] <= arr[mid]) {
      if (arr[low] <= mini) {
        mini = arr[low];
        ind = low;
      }
      low = mid + 1;
    }

    else if (arr[mid] <= arr[high]) {
      if (arr[mid] <= arr[high]) {
        mini = arr[mid];
        ind = mid;
      }
      high = mid - 1;
    }
  }

  return ind;
}