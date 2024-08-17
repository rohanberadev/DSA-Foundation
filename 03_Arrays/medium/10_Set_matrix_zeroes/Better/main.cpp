#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

vector<vector<int>> setMatrixZeroes(vector<vector<int>> mat) {  
  int n = mat.size();
  int m = mat[0].size();

  
}

int main() {
  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input file.";
    return 1;
  } 

  streambuf* cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());

  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output file.";
    return 1;
  }
  
  streambuf* coutbuf = cout.rdbuf();
  cout.rdbuf(outfile.rdbuf());
  
  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> mat;
  for (int i = 0; i < n; i++) {
    vector<int> arr;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      arr.push_back(x);
    }
    mat.push_back(arr);
  }

  vector<vector<int>> ans = setMatrixZeroes(mat);
  for (vector<int> arr : ans) {
    for (int cell : arr) {
      cout << cell << " ";
    }
    cout << endl;
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
