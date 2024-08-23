#include <bits/stdc++.h>
using namespace std;

bool checkArraySorted(vector<int> &arr) {
  int n = arr.size();

  for (int i = 1; i < n; i++) {
    if (arr[i - 1] > arr[i])
      return false;
  }

  return true;
}

// Link -
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
