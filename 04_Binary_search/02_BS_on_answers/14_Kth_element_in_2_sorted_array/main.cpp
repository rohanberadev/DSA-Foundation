#include <bits/stdc++.h>
using namespace std;

int kthElement(int k, vector<int> &arr1, vector<int> &arr2) {
  int n1 = arr1.size();
  int n2 = arr2.size();

  if (n1 > n2) {
    return kthElement(k, arr2, arr1);
  }

  int low = max(0, k - n2);
  int high = min(k, n1);

  while (low <= high) {
    int mid1 = (low + high) / 2;
    int mid2 = k - mid1;

    int r1 = mid1 < n1 ? arr1[mid1] : INT_MAX;
    int r2 = mid2 < n2 ? arr2[mid2] : INT_MAX;
    int l1 = mid1 - 1 >= 0 ? arr1[mid1 - 1] : INT_MIN;
    int l2 = mid2 - 1 >= 0 ? arr2[mid2 - 1] : INT_MIN;

    if (l1 <= r2 && l2 <= r1) {
      return max(l1, l2);
    }

    else if (l1 > r2) {
      high = mid1 - 1;
    }

    else {
      low = mid1 + 1;
    }
  }

  return -1;
}

// Link -
// https://bit.ly/3Amcomr