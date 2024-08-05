#include <bits/stdc++.h>
using namespace std;

void combinationSum_util
(int ind, int len, int target, int n, vector<int> &ds, vector<vector<int>> &ans) {
	if (target == 0 && len == 0) {
		ans.push_back(ds);
		return;
	}
	if (ind > n || len < 0) return;
		
	if (ind <= target) {
		ds.push_back(ind);
		combinationSum_util(ind+1, len-1, target-ind, n, ds, ans);
		ds.pop_back();
	}
	
	combinationSum_util(ind+1, len, target, n, ds, ans);
} 

vector<vector<int>> combinationSum(int k, int n) { 
	vector<vector<int>> ans;
	vector<int> ds;

	combinationSum_util(1, k, n, 9, ds, ans);

	return ans;
}

int main() {

	int k;
	cin >> k;

	int n;
	cin >> n;

	vector<vector<int>> ans = combinationSum(k, n);

	for (auto res : ans) {
		for (auto it : res) {
			cout << it << " ";
		}
		cout << endl;
	}
	
	return 0;

}