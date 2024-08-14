#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

// Time :- O((N / 2) + (2 * N))
// Space :- (1)
int celebrityProblem(vector<vector<int>> mat) {
  int n = mat.size();
  int m = mat[0].size();

  int top = 0;
  int down = n-1;
  
  while (top < down) {
    // top knows down but down don't know top.
    if (mat[top][down] == 1 && mat[down][top] == 0) top++;
    // down knows top but top don't know down.
    else if (mat[down][top] == 1 && mat[top][down] == 0) down--;
    else {
      // top and down both knows each other or not knows each other then they are not a celebrity for sure.
      // because if both knows each other then they are not a celeb by the given condition.
      // or if they don't know each other that means both can't be a celeb because celeb should be known by everyone (n-1).
      top++;
      down--;
    }
  }

  if (top == down) {
    // cheching if he knows somebody.
    for (int i = 0; i < n; i++) {
      if (mat[top][i] == 1) return -1;
    }

    // checking if everyone knows him except him knowing him.
    for (int i = 0; i < m; i++) {
      if (i == top) continue;
      if (mat[i][top] == 0) return -1;
    }

    return top;
  }
  else return -1;
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