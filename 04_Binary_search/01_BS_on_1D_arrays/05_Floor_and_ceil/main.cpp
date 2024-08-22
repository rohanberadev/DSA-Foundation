#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> &arr, int n, int x) {
  int low = 0, high = n - 1;
  int ind = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] <= x) {
      ind = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  if (ind == -1) {
    return -1;
  }

  return arr[ind];
}

int ceil(vector<int> &arr, int n, int x) {
  int low = 0, high = n - 1;
  int ind = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] >= x) {
      ind = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  if (ind == -1) {
    return -1;
  }

  return arr[ind];
}

vector<int> getFloorAndCeil(vector<int> arr, int x) {
  int n = arr.size();

  int f = floor(arr, n, x);
  int c = ceil(arr, n, x);

  return {f, c};
}