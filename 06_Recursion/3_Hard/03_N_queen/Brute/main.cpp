#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> nQueens(int n) {
	vector<vector<string>> ans;
	vector<string> board(n);
	string s(n, '.');

	for (int i = 0; i < n; i++) {
		board[i] = s;
	}

	// is safe 
	function<bool(int, int)> isSafe = [&](int r, int c) -> bool {
		int row = r;
		int col = c;

		while (r >= 0 && c >= 0) {
			if (board[r][c] == 'Q') return false;
			r--;
			c--;
		}

		c = col;
		r = row;
		while (r < n && c < n) {
			if (board[r][c] == 'Q') return false;
			r++;
			c--;
		}

		c = col;
		r = row;
		while (c >= 0) {
			if (board[r][c] == 'Q') return false;
			c--;
		}

		return true;
	};

	// backtrack
	function<void(int)> backtrack = [&](int c) -> void {
		if (c == n) {
			ans.push_back(board);
			return;
		}

		for (int r = 0; r < n; r++) {
			if (isSafe(r, c)) {
				board[r][c] = 'Q';
				backtrack(c+1);
				board[r][c] = '.';
			}
		}
	};

	backtrack(0);

	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<vector<string>> ans = nQueens(n);

	for (auto res : ans) {
		cout << "[ ";
		for (auto it : res) {
			cout << "'" << it << "'" << " ";
		}
		cout << "]" << endl;
	}

	return 0;
}