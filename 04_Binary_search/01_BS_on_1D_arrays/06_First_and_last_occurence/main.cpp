#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &arr, int low, int high, int target) {
  int ind = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == target) {
      ind = mid;
      high = mid - 1;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return ind;
}

int lastOccurence(vector<int> &arr, int low, int high, int target) {
  int ind = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == target) {
      ind = mid;
      low = mid + 1;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return ind;
}

vector<int> searchRange(vector<int> arr, int target) {
  int n = arr.size();

  int first = firstOccurence(arr, 0, n - 1, target);

  if (first == -1) {
    return {-1, -1};
  }

  int last = lastOccurence(arr, first, n - 1, target);

  return {first, last};
}

// Link -
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/