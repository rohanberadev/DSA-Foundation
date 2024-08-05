#include <bits/stdc++.h>
using namespace std;

void printAllSubsequence_recursive(vector<int> &arr, vector<int> &ds, int ind, int n) {
	if (ind >= n) {
		cout << "[ ";
		for (auto it : ds) {
			cout << it << " ";
		}
		cout << "]" << endl;
		return;
	}

	ds.push_back(arr[ind]);
	printAllSubsequence_recursive(arr, ds, ind+1, n);

	ds.pop_back();
	printAllSubsequence_recursive(arr, ds, ind+1, n);
}

void printAllSubsequence_powerSet(vector<int> &arr, int n) {
	for (int num = 0; num < (1<<n); num++) {
		cout << "[ ";
		for (int i = 0; i < n; i++) {
			if (num & (1<<i)) {
				cout << arr[i] << " ";
			}
		}
		cout << "]" << endl;
	}
}

int main() {
	int size;
	cin >> size;

	vector<int> arr(size);
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	vector<int> ds;
	printAllSubsequence_recursive(arr, ds, 0, size);

	cout << endl;

	printAllSubsequence_powerSet(arr, size);

	return 0;
}