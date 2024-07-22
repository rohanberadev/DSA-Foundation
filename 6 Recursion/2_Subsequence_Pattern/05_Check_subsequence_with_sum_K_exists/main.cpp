#include <bits/stdc++.h>
using namespace std;

bool checkExistSubsequenceWithSumK_util
(vector<int> &arr, vector<int> &ds, int ind, int n, int sum, int target) {
	if (ind >= n) {
		if (sum == target) {
			return true;
		}
		return false;
	}

	sum += arr[ind];
	ds.push_back(arr[ind]);
	if (checkExistSubsequenceWithSumK_util(arr, ds, ind+1, n, sum, target)) return true;

	sum -= arr[ind];
	ds.pop_back();
	return checkExistSubsequenceWithSumK_util(arr, ds, ind+1, n, sum, target);
}

bool checkExistSubsequenceWithSumK(vector<int> &arr, int n, int target) {
	vector<int> ds;
	return checkExistSubsequenceWithSumK_util(arr, ds, 0, n, 0, target);
}

int main() {

	int size;
	cin >> size;

	vector<int> arr(size);
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	int target;
	cin >> target;

	cout << checkExistSubsequenceWithSumK(arr, size, target);

	return 0;
}