#include <bits/stdc++.h>
using namespace std;

// Time :- O(4^(m*n))
// Space :-  O(m*n)
void backtrack(vector<vector<int>> &maze, vector<string> &ans, string path,
               int row, int col, int n, int m) {

  if (row == n - 1 && col == m - 1 && maze[row][col] == 1) {
    ans.push_back(path);
    return;
  }

  if (row == n || col == m || row < 0 || col < 0 || maze[row][col] == -1 ||
      maze[row][col] == 0) {
    return;
  }

  maze[row][col] = -1;

  // up
  backtrack(maze, ans, path + "U", row - 1, col, n, m);
  // down
  backtrack(maze, ans, path + "D", row + 1, col, n, m);
  // left
  backtrack(maze, ans, path + "L", row, col - 1, n, m);
  // right
  backtrack(maze, ans, path + "R", row, col + 1, n, m);

  maze[row][col] = 1;
}

vector<string> findPath(vector<vector<int>> &maze) {
  int n = maze.size();
  int m = maze[0].size();

  vector<string> ans;

  backtrack(maze, ans, "", 0, 0, n, m);

  return ans;
}

// Link -
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1