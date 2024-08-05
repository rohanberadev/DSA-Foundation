#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> sudokuSolver(vector<vector<char>> &board) {
	function<bool(int, int, char)> isValid = [&](int row, int col, char c) -> bool {
		for (int i = 0; i < 9; i++) {
			if (board[row][i] == c) return false;

			if (board[i][col] == c) return false;

			if (board[3 * (row/3) + i / 3][3 * (col/3) + i % 3] == c) return false;
		}

		return true;
	};

	function<bool()> backtrack = [&]() -> bool {
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {
				if (board[row][col] != '.') continue;

				for (char c = '1'; c <= '9'; c++) {
					if (isValid(row, col, c)) {
						board[row][col] = c;

						if (backtrack()) return true;
						else board[row][col] = '.';
					}
				}
				return false;
			}
		}
		return true;
	};

	backtrack();

	return board;
}

int main() {

	vector<vector<char>> board = {
	    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};

	for (auto row : board) {
		for (auto it : row) {
			cout << it << " ";
		}
		cout << endl;
	}

	cout << endl << endl;

	vector<vector<char>> solvedBoard = sudokuSolver(board);

	for (auto row : solvedBoard) {
		for (auto it : row) {
			cout << it << " ";
		}
		cout << endl;
	}

	return 0;
}