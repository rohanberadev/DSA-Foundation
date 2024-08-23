#include <bits/stdc++.h>
using namespace std;

int numberOf1s(vector<int> &arr, int n) {
  int low = 0, high = n - 1;
  int first = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == 1) {
      first = mid;
      high = mid - 1;
    }

    else {
      low = mid + 1;
    }
  }

  if (first == -1) {
    return 0;
  }

  low = first, high = n - 1;
  int last = first;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == 1) {
      last = mid;
      low = mid + 1;
    }

    else {
      high = mid - 1;
    }
  }

  return last - first + 1;
}

int rowWithMax1s(vector<vector<int>> &mat) {
  int n = mat.size();
  int m = mat[0].size();

  int maxi = 0;
  int ind = -1;

  for (int i = 0; i < n; i++) {
    int cnt = numberOf1s(mat[i], n);
    if (maxi < cnt) {
      ind = i;
      maxi = cnt;
    }
  }

  return ind;
}

// Link -
// https://bit.ly/3QNDw2W