#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &mat) {
  int n = mat.size();
  int m = mat[0].size();
  int c0 = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 0) {
        mat[i][0] = 0;

        if (j == 0) c0 = 0;
        else mat[0][j] = 0;
      }
    }
  }

  for (int j = 1; j < m; j++) {
    if (mat[0][j] == 0) {
      for (int i = 0; i < n; i++) {
        mat[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (mat[i][0] == 0) {
      for (int j = 0; j < m; j++) {
        mat[i][j] = 0;
      }
    }
  }

  if (c0 == 0) {
    for (int i = 0; i < n; i++) {
      mat[i][0] = 0;
    }
  }
}