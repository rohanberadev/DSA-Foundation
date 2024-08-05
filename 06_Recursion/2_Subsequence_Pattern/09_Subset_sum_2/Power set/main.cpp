#include <bits/stdc++.h>
using namespace std;

// Time :- O(((2^N) * N) + (N * Log N) + (N)) Space :- O(N + 2^N)
vector<vector<int>> subset(vector<int> &arr, int n) {
	vector<vector<int>> ans;
	set<vector<int>> st;

	for (int num = 0; num < (1 << n); num++) {
		vector<int> ds;

		for (int i = 0; i < n; i++) {
			if (num & (1 << i)) {
				ds.push_back(arr[i]);
			}
		}
		ans.push_back(ds);
	}

	for (auto it : ans) {
		st.insert(it);
	}

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