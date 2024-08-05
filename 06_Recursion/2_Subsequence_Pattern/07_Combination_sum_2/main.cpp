#include <bits/stdc++.h>
using namespace std;

void combinationSum_util
(vector<int> &arr, int ind, int n, int target, vector<int> &ds, vector<vector<int>> &ans) {
	if (target == 0) {
		vector<int> res;
		for (auto it : ds) {
			res.push_back(it);
		}
		ans.push_back(res);
		return;
	}

	if (ind >= n) return;

	for (int i = ind; i < n; i++) {
		if (i > ind && arr[i-1] == arr[i]) continue;
		if (arr[i] > target) break;

		ds.push_back(arr[i]);
		combinationSum_util(arr, i+1, n, target-arr[i], ds, ans);
		ds.pop_back();
	}

}

vector<vector<int>> combinationSum(vector<int> &arr, int n, int target) {
	vector<vector<int>> ans;
	vector<int> ds;

	sort(arr.begin(), arr.end());

	combinationSum_util(arr, 0, n, target, ds, ans);

	return ans;
}

int main() {

	int size;
	cin >> size;

	int target;
	cin >> target;

	vector<int> arr(size);
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	vector<vector<int>> ans = combinationSum(arr, size, target);

	for (auto res : ans) {
		for (auto it : res) {
			cout << it << " ";
		}
		cout << endl;
	}

	return 0;
}