#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int target) {
  int n = arr.size();

  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] < target) {
      low = mid + 1;
    } else if (arr[mid] > target) {
      high = mid - 1;
    } else {
      return mid;
    }
  }

  return -1;
}