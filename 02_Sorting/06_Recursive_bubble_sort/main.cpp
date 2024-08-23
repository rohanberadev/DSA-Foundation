#include <bits/stdc++.h>
using namespace std;

void bubbleSort_util(vector<int> &arr, int n) {
  if (n == 0)
    return;

  for (int i = 1; i <= n; i++) {
    if (arr[i - 1] > arr[i])
      swap(arr[i - 1], arr[i]);
  }

  bubbleSort_util(arr, n - 1);
}

void bubbleSort(vector<int> &arr) { bubbleSort_util(arr, arr.size() - 1); }

// Link -
// https://bit.ly/3QV65vI