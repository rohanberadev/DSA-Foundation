#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int largestHistogram(vector<int> arr) {
  int n = arr.size();

  stack<int> st;
  int maxArea = 0;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      int ind = st.top();
      st.pop();
      int nse = i;
      int pse = st.empty() ? -1 : st.top();

      int left = ind - pse;
      int right = nse - ind;

      int width = left + right - 1;

      maxArea = max(maxArea, arr[ind] * width); 
    }
    st.push(i);
  }

  while (!st.empty()) {
    int ind = st.top();
    st.pop();
    int nse = n;
    int pse = st.empty() ? -1 : st.top();

    int left = ind - pse;
    int right = nse - ind;

    int width = left + right - 1;
    maxArea = max(maxArea, arr[ind] * width);
  }

  return maxArea;
}

int maximalRectangle(vector<vector<int>> matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  vector<vector<int>> histograms(n, vector<int>(m, 0));

  for (int j = 0; j < m; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += matrix[i][j] - '0';
      if (matrix[i][j] == '0') sum = 0;
      histograms[i][j] = sum;
    }
  }

  int maxArea = 0;

  for (int i = 0; i < n; i++) {
    maxArea = max(maxArea, largestHistogram(histograms[i]));
  } 
  
  return maxArea;
}

int main() {
  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input file.";
    return 1;
  }

  streambuf *cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());
  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output file.";
    return 1;
  }

  streambuf *coutbuf = cout.rdbuf();
  cout.rdbuf(outfile.rdbuf());

  vector<vector<int>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

  cout << maximalRectangle(matrix);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}