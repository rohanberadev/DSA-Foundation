#include <bits/stdc++.h>
using namespace std;

// Time :- O(2^N) Space :- O(N)
void subset_util(vector<int> &arr, int ind, int n, vector<int> &ds, vector<vector<int>> &ans) {
	ans.push_back(ds);
	if (ind >= n) return;

	for (int i = ind; i < n; i++) {
		if (i > ind && arr[i-1] == arr[i]) continue;

		ds.push_back(arr[i]);
		subset_util(arr, i+1, n, ds, ans);
		ds.pop_back();
	}
}

// Time :- O((2^N) + (N * Log(N))) Space :- O(N)
vector<vector<int>> subset(vector<int> &arr, int n) {
	sort(arr.begin(), arr.end());

	vector<vector<int>> ans;
	vector<int> ds;

	subset_util(arr, 0, n, ds, ans);

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