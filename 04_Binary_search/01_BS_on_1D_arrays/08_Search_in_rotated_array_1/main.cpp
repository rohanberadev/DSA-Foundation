#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int target) {
  int n = arr.size();

  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == target) {
      return mid;
    }

    if (arr[low] <= arr[mid]) {
      if (arr[low] <= target && target < arr[mid]) {
        high = mid - 1;

      } else {
        low = mid + 1;
      }

    } else if (arr[high] >= arr[mid]) {
      if (arr[high] >= target && target > arr[mid]) {
        low = mid + 1;

      } else {
        high = mid - 1;
      }
    }
  }

  return -1;
}

// Link -
// https://leetcode.com/problems/search-in-rotated-sorted-array/