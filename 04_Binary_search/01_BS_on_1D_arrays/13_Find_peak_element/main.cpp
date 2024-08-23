#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
  int n = arr.size();

  if (n == 1) {
    return 0;
  }

  else if (arr[0] > arr[1]) {
    return 0;
  }

  else if (arr[n - 1] > arr[n - 2]) {
    return n - 1;
  }

  int low = 1, high = n - 2;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
      return mid;
    }

    else if (arr[mid] > arr[mid - 1] && arr[mid + 1] > arr[mid]) {
      low = mid + 1;
    }

    else {
      high = mid - 1;
    }
  }

  return -1;
}

// Link -
// https://leetcode.com/problems/find-peak-element/