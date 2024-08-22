#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &mat) {
  int n = mat.size();
  int m = mat[0].size();

  int top = 0, bottom = n-1, left = 0, right = m-1;

  vector<int> res;

  while (top <= bottom && left <= right) {
    for (int i = left; i <= right; i++) {
      res.push_back(mat[top][i]);
    }
    top++;

    for (int i = top; i <= bottom; i++) {
      res.push_back(mat[i][right]);
    }
    right--;

    if(top <= bottom) {
      for (int i = right; i >= left; i--) {
        res.push_back(mat[bottom][i]);
      }
      bottom--;
    }

    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        res.push_back(mat[i][left]);
      }
      left++;
    }
  }

  return res;
}