#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int> &arr1, int m, vector<int> &arr2, int n) {
  int i = m-1;
  int j = 0;

  while (i >= 0 && j < n) {
    if (arr1[i] > arr2[j]) {
      swap(arr1[i], arr2[j]);
    }
    else break;
    i--, j++;
  }

  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());
}