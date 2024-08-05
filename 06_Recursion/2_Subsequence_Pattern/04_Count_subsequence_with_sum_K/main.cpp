#include<bits/stdc++.h>
using namespace std;

int countAllSubsequenceWithSumK_util
(vector<int> &arr, vector<int> &ds, int ind, int n, int sum, int target) {
	int count = 0;
	if (ind >= n) {
		if (sum == target) {
			count += 1;
			return count;
		}
		return count;
	}

	sum += arr[ind];
	ds.push_back(arr[ind]);
	count += countAllSubsequenceWithSumK_util(arr, ds, ind+1, n, sum, target);

	sum -= arr[ind];
	ds.pop_back();
	count += countAllSubsequenceWithSumK_util(arr, ds, ind+1, n, sum, target);

	return count;
}

int countAllSubsequenceWithSumK(vector<int> &arr, int n, int target) {
	vector<int> ds;
	return countAllSubsequenceWithSumK_util(arr, ds, 0, n, 0, target);
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

	cout << countAllSubsequenceWithSumK(arr, size, target);

	return 0;
}
