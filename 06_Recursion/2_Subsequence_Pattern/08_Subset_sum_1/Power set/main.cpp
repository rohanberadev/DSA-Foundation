#include <bits/stdc++.h>
using namespace std;

// Time :- O(((2^N ) * N) + (N * Log(N))) Space :- O(N)
vector<int> subsetSum(vector<int> &arr, int n) {
	vector<int> ans;

	for (int num = 0; num < (1 << n); num++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (num & (1 << i)) {
				sum += arr[i];
			}
		}
		ans.push_back(sum);
	}
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