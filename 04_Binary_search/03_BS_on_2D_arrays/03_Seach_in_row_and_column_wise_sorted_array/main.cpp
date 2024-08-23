#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> mat, int target) {
  int n = mat.size();
  int m = mat[0].size();

  int row = 0, col = m - 1;

  while (row < n && col >= 0) {
    if (mat[row][col] == target) {
      return true;
    }

    else if (mat[row][col] < target) {
      row++;
    }

    else {
      col--;
    }
  }

  return false;
}

// Link -
// https://leetcode.com/problems/search-a-2d-matrix-ii/