#include <bits/stdc++.h>
using namespace std;

// Time :- O(2^N) Space :- O(N)
void subset_util(vector<int> &arr, int ind, int n, vector<int> &ds, vector<vector<int>> &ans) {
	if (ind >= n) {
		ans.push_back(ds);
		return;
	}

	// pick the eleemnt.
	ds.push_back(arr[ind]);
	subset_util(arr, ind+1, n, ds, ans);

	// dont't pick the element.
	ds.pop_back();
	subset_util(arr, ind+1, n, ds, ans);
}

// Time :- O(2^N + (N * Log(N)) + N) Space :- O(N + 2^N)
vector<vector<int>> subset(vector<int> &arr, int n) {
	vector<vector<int>> ans;
	vector<int> ds;

	// Time :- O(2^N)
	subset_util(arr, 0, n, ds, ans);

	// Time :- O(N * Log(N))
	set<vector<int>> st;
	for (auto it : ans) {
		st.insert(it);
	}

	// Time :- O(N)
	ans.clear();
	for (auto it : st) {
		ans.push_back(it);
	}

	return ans;
}

int main() {

	int size;
	cin >> size;

	vector<int> arr(size);
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	vector<vector<int>> ans = subset(arr, size);
	for (auto res : ans) {
		cout << "[ ";
		for (auto it : res) {
			cout << it << " ";
		} 
		cout << "]" << endl;
	}

	return 0;
}