#include <bits/stdc++.h>
using namespace std;

void printAllCombinationSum_util
(vector<int> &arr, vector<int> &ds, int ind, int n, int target) {
	if (target == 0 ){
		for (auto it : ds) {
			cout << it << " ";
		}
		cout << endl;
		return;
	}

	if (ind >= n) return;

	if (arr[ind] <= target) {
		ds.push_back(arr[ind]);
		printAllCombinationSum_util(arr, ds, ind, n, target-arr[ind]);
		ds.pop_back();
	}

	printAllCombinationSum_util(arr, ds, ind+1, n, target);
}

void printAllCombinationSum(vector<int> &arr, int n, int target) {
	vector<int> ds;
	printAllCombinationSum_util(arr, ds, 0, n, target);
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

	printAllCombinationSum(arr, size, target);

	return 0;
}