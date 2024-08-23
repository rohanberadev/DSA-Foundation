#include <bits/stdc++.h>
using namespace std;

int findMaxCol(vector<vector<int>> &mat, int col, int n) {
  int maxi = INT_MIN;
  int ind = -1;

  for (int i = 0; i < n; i++) {
    if (maxi < mat[i][col]) {
      maxi = mat[i][col];
      ind = i;
    }
  }

  return ind;
}

vector<int> findPeakGrid(vector<vector<int>> &mat) {
  int n = mat.size();
  int m = mat[0].size();

  int low = 0, high = m - 1;

  while (low <= high) {
    int col = (low + high) / 2;
    int row = findMaxCol(mat, col, n);

    int left = col - 1 >= 0 ? mat[row][col - 1] : -1;
    int right = col + 1 < m ? mat[row][col + 1] : -1;

    if (mat[row][col] > left && mat[row][col] > right) {
      return {row, col};
    }

    else if (left < right) {
      low = col + 1;
    }

    else {
      high = col - 1;
    }
  }

  return {-1, -1};
}

// Link -
// https://leetcode.com/problems/find-a-peak-element-ii/