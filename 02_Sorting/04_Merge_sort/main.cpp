#include <bits/stdc++.h>
using namespace std;

void mergeArr(vector<int> &arr, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;

  vector<int> temp;

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right])
      temp.push_back(arr[left++]);
    else
      temp.push_back(arr[right++]);
  }

  while (left <= mid)
    temp.push_back(arr[left++]);
  while (right <= high)
    temp.push_back(arr[right++]);

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

// Link -
// https://bit.ly/3A30Anw