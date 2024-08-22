#include <bits/stdc++.h>
using namespace std;

int firstOccurences(int arr[], int low, int high, int target) {
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

int lastOccurences(int arr[], int low, int high, int target) {
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

int count(int arr[], int n, int target) {
  int first = firstOccurences(arr, 0, n - 1, target);

  if (first == -1) {
    return 0;
  }

  int last = lastOccurences(arr, first, n - 1, target);

  return last - first + 1;
}