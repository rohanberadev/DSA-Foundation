#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &mat) {
  int n = mat.size();
  int m = mat[0].size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      swap(mat[i][j], mat[j][i]);
    }
  }
}

void reverseArr(vector<int> &arr) {
  int i = 0, j = arr.size()-1;

  while (i < j) swap(arr[i++], arr[j--]);
}

void rotate (vector<vector<int>> &mat) {
  int n = mat.size();
  int m = mat[0].size();

  transpose(mat);
  
  for (int i = 0; i < n; i++) {
    reverseArr(mat[i]);
  }
  
}