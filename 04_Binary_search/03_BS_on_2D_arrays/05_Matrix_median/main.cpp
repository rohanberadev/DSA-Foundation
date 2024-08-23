#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int n, int target) {
  int low = 0, high = n - 1;
  int ans = n;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] > target) {
      ans = mid;
      high = mid - 1;
    }

    else {
      low = mid + 1;
    }
  }

  return ans;
}

int countSmallerVal(vector<vector<int>> &mat, int R, int C, int target) {
  int cnt = 0;
  for (int i = 0; i < R; i++) {
    cnt += upperBound(mat[i], C, target);
  }

  return cnt;
}

int findMin(vector<vector<int>> &mat, int R, int C) {
  int mini = INT_MAX;

  for (int i = 0; i < R; i++) {
    mini = min(mini, mat[i][0]);
  }

  return mini;
}

int findMax(vector<vector<int>> &mat, int R, int C) {
  int maxi = INT_MIN;

  for (int i = 0; i < R; i++) {
    maxi = max(maxi, mat[i][C - 1]);
  }

  return maxi;
}

int median(vector<vector<int>> &mat, int R, int C) {
  int n = R * C / 2;
  int low = findMin(mat, R, C);
  int high = findMax(mat, R, C);

  while (low <= high) {
    int mid = (low + high) / 2;
    int smallerVal = countSmallerVal(mat, R, C, mid);

    if (smallerVal <= n / 2) {
      low = mid + 1;
    }

    else {
      high = mid - 1;
    }
  }

  return high;
}