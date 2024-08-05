#include<bits/stdc++.h>
using namespace std;

// Time :- O(4^(m*n))
// Space :-  O(m*n) 
vector<string> ratInAMaze(vector<vector<int>> &maze, int n) {
	vector<string> ans;
	vector<vector<int>> vis(n, vector<int>(n, 0));

	function<void(int, int, string)> backtrack = [&](int r, int c, string path) -> void {
		if (r == n-1 && c == n-1) {
			ans.push_back(path);
			return;
		}

		// up or upwards
		if (r-1 >= 0 && !vis[r-1][c] && maze[r-1][c] == 1) {
			vis[r][c] = 1;
			backtrack(r-1, c, path + "U");
			vis[r][c] = 0;
		}

		// down or downwards
		if (r+1 < n && !vis[r+1][c] && maze[r+1][c] == 1) {
			vis[r][c] = 1;
			backtrack(r+1, c, path + "D");
			vis[r][c] = 0;
		}

		// left or backwards
		if (c-1 >= 0 && !vis[r][c-1] && maze[r][c-1] == 1) {
			vis[r][c] = 1;
			backtrack(r, c-1, path + "L");
			vis[r][c] = 0;
		}

		// right or towards
		if (c+1 < n && !vis[r][c+1] && maze[r][c+1] == 1) {
			vis[r][c] = 1;
			backtrack(r, c+1, path + "R");
			vis[r][c] = 0;
		}
	};


	if (maze[0][0] == 1) backtrack(0, 0, "");

	return ans;
}

int main() {

	int n = 4;
	vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

   for (int r = 0; r < n; r++) {
	   	for (int c = 0; c < n; c++) {
	   		cout << maze[r][c] << " ";
	   	}
	   	cout << endl;
   }
   cout << endl;

   vector<string> ans = ratInAMaze(maze, n);

   for (auto it : ans) {
   		cout << it << endl;
   }

	return 0;
}