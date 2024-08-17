#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> mat) {
  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int>> res;

  for (int j = 0; j < m; j++) {
    vector<int> arr;
    for (int i = 0; i < n; i++) {
      arr.push_back(mat[i][j]);
    }
    mat.push_back(arr);
  }

  return res;
}

void reverseArr(vector<int> &arr) {
  int n = arr.size();
  int i = 0, j = n-1;

  while (i < j) swap(arr[i++], arr[j--]);
}

void rotate(vector<vector<int>> &mat) {
  int n = mat.size();
  int m = mat.size();

  vector<vector<int>> transposedMat = transpose(mat);

  for (int i = 0; i < n; i++) {
    reverseArr(mat[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mat[i][j] = transposedMat[i][j];
    }
  }
}