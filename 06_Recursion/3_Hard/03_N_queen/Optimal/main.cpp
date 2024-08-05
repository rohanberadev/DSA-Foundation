#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> nQueens(int n) {
	vector<vector<string>> ans;
	vector<string> board(n);
	string s(n, '.');

	for (int i = 0; i < n; i++) {
		board[i] = s;
	}

	vector<bool> leftRow(n);
    vector<bool> lowerDiagonal(2*n - 1);
    vector<bool> upperDiagonal(2*n - 1);

	function<bool(int, int)> isSafe = [&](int r, int c) -> bool {
		return !(leftRow[r] || lowerDiagonal[r+c] || upperDiagonal[(n-1) + (c-r)]);
	};

	function<void(int)> backtrack = [&](int c) -> void {
		if (c == n) {
			ans.push_back(board);
			return;
		}

		for (int r = 0; r < n; r++) {
			if (isSafe(r, c)) {
				leftRow[r] = true;
				lowerDiagonal[r+c] = true;
				upperDiagonal[(n-1) + (c-r)] = true;

				board[r][c] = 'Q';
				backtrack(c+1);
				board[r][c] = '.';

				leftRow[r] = false;
				lowerDiagonal[r+c] = false;
				upperDiagonal[(n-1) + (c-r)] = false;
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