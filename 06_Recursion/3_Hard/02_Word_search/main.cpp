#include <bits/stdc++.h>
using namespace std;

bool searchNext(vector<vector<char>> &board, string &word, int row, int col,
                int ind, int n, int m) {

  if (ind == word.length()) {
    return true;
  }

  if (row == n || col == m || row < 0 || col < 0 ||
      board[row][col] != word[ind] || board[row][col] == '!') {
    return false;
  }

  char c = board[row][col];
  board[row][col] = '!';

  bool top = searchNext(board, word, row - 1, col, ind + 1, n, m);
  bool down = searchNext(board, word, row + 1, col, ind + 1, n, m);
  bool left = searchNext(board, word, row, col - 1, ind + 1, n, m);
  bool right = searchNext(board, word, row, col + 1, ind + 1, n, m);

  return top || down || left || right;
}

bool wordSearch(vector<vector<char>> &board, string word) {
  int n = board.size();
  int m = board[0].size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (searchNext(board, word, i, j, 0, n, m)) {
        return true;
      }
    }
  }

  return false;
}