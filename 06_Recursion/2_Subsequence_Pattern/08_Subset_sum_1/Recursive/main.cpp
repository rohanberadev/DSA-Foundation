#include <bits/stdc++.h>
using namespace std;

// Time :- O(2^N) Space :- O(1)
void subsetSum_util
(vector<int> &arr, int ind, int n, int sum, vector<int> &ans) {
	if (ind >= n) {
		ans.push_back(sum);
		return;
	}

	// pick the element. 
	sum += arr[ind];
	subsetSum_util(arr, ind+1, n, sum, ans);

	// dont't pick the element.
	sum -= arr[ind];
	subsetSum_util(arr, ind+1, n, sum, ans);
	
}

// Time :- O((2^N) + (N * Log(N))) Space :- O(1)
vector<int> subsetSum(vector<int> &arr, int n) {
	vector<int> ans; 

	subsetSum_util(arr, 0, n, 0, ans);

	// Time :- O(N * Log(N))
	sort(ans.begin(), ans.end());

	return ans;
}

int main() {

	int size;
	cin >> size;

	vector<int> arr(size);
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	vector<int> ans = subsetSum(arr, size);
	for (auto it : ans) {
		cout << it << " ";
	}

	return 0;
}