#include <bits/stdc++.h>
using namespace std;

bool checkVisited(int row, int col, set<pair<int, int>> &path) {
	return path.find({row, col}) != path.end();
}

bool wordSearch(vector<vector<char>> &board, string &word) {
	set<pair<int, int>> path;
	int ROWS = board.size(), COLS = board[0].size();

	function<bool(int, int, int)> dfs = [&](int r, int c, int ind) -> bool {
			
		if (ind == word.size()) return true;

		if (r < 0 || c < 0 ||
			r >= ROWS || c >= COLS ||
			word[ind] != board[r][c] ||
			checkVisited(r, c, path)) return false;

		path.insert({r, c});

		bool top = dfs(r-1, c, ind+1);
		bool bottom = dfs(r+1, c, ind+1);
		bool left = dfs(r, c-1, ind+1);
		bool right = dfs (r, c+1, ind+1);

		bool res = top || bottom || left || right;

		path.erase({r, c});			

		return res;
	};	

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (dfs(i, j, 0)) return true;	
		}
	}

	return false;
}

int main() {
	int m, n;
	cin >> m >> n;

	string word;
	cin >> word;

	vector<vector<char>> board(m);
	for (int i = 0; i < m; i++) {
		vector<char> chars(n);
		for (int j = 0; j < n; j++) {
			cin >> chars[j];
		}
		board[i] = chars;
	}

	for (auto chars : board) {
		for (auto it : chars) {
			cout << it << " ";
		}
		cout << endl;
	}

	cout << endl;

	bool found = wordSearch(board, word);
	if (found) cout << "Found!";
	else cout << "Not found!";

	return 0;
}