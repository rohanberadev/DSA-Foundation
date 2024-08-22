#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int n, long long maxPages) {
  long long pages = 0;
  int stud = 1;

  for (int i = 0; i < n; i++) {
    if (pages + arr[i] <= maxPages) {
      pages += arr[i];
    }

    else {
      pages = arr[i];
      stud++;
    }
  }

  return stud;
}

int findMax(vector<int> &arr, int n) {
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, arr[i]);
  }

  return maxi;
}

int summation(vector<int> &arr, int n) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  return sum;
}

int findPages(vector<int> &arr, int n, int m) {
  if (n < m) {
    return -1;
  }

  long long low = findMax(arr, n), high = summation(arr, n);

  while (low <= high) {
    long long mid = (low + high) / 2;

    if (countStudents(arr, n, mid) <= m) {
      high = mid - 1;
    }

    else {
      low = mid + 1;
    }
  }

  return low;
}