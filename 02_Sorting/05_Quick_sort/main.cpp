#include <bits/stdc++.h>
using namespace std;

int findPartionIndex(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int left = low;
  int right = high;

  while (left < right) {
    while (left < high && arr[left] <= pivot)
      left++;

    while (right > low && arr[right] >= pivot)
      right--;

    if (left < right)
      swap(arr[left], arr[right]);
  }

  swap(arr[right], arr[low]);

  return right;
}

void quickSort_util(vector<int> &arr, int low, int high) {
  if (low < high) {
    int partition = findPartionIndex(arr, low, high);

    quickSort_util(arr, low, partition - 1);
    quickSort_util(arr, partition + 1, high);
  }
}

void quickSort(vector<int> &arr) { quickSort_util(arr, 0, arr.size() - 1); }

// Link -
// https://bit.ly/3dsEbIK