#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
  vector<int> temp;
  int i = low, j = mid + 1;

  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
    else temp.push_back(arr[j++]);
  }

  while (i <= mid) temp.push_back(arr[i++]);
  while (j <= high) temp.push_back(arr[j++]);

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i-low];
  }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
  int right = mid + 1;
  int cnt = 0;

  for (int i = low; i <= mid; i++) {
    while (right <= high && 1ll * arr[i] > 1ll * arr[right] * 2) right++;
    cnt += (right - (mid + 1));
  }
  return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
  int cnt = 0;

  if (low >= high) return cnt;
  int mid = (low + high) / 2;
  cnt += mergeSort(arr, low, mid);
  cnt += mergeSort(arr, mid+1, high);
  cnt += countPairs(arr, low, mid, high);
  merge(arr, low, mid, high);

  return cnt;
}

int reversePairs(vector<int> arr) {
  int n = arr.size();

  return mergeSort(arr, 0, n-1);
} 