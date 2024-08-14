#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

// Time :- O((2 * N) + (N * M))
// Space :- (2 * N)
int celebrityProblem(vector<vector<int>> mat) {
  int n = mat.size();
  int m = mat[0].size();

  int knowCeleb[n];
  bool celebKnow[n];

  for (int i = 0; i < n; i++) {
    knowCeleb[i] = 0;
    celebKnow[i] = false;
  }

  for (int i = 0; i < n; i++) {
    bool doesKnow = false;
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 1) {
          knowCeleb[j] += 1; 
          doesKnow = true;
      }
    }
    celebKnow[i] = doesKnow;
  }

  for (int i = 0; i < n; i++) {
    if (knowCeleb[i] == n-1 && celebKnow[i] == false) return i;
  }

  return -1;
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

  vector<vector<int>> mat = {{0, 1, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

  cout << celebrityProblem(mat) << " is a celebrity.";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}