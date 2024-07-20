#include <bits/stdc++.h>
using namespace std;

void printNameNTimes(string name, int n) {
	if (n == 0) {
		return;
	}

	cout << name << endl;
	printNameNTimes(name, n-1);
}

void printNLinearly(int n) {
	if (n == 0) {
		return;
	}

	printNLinearly(n-1);
	cout << n << " ";
}

void printNReverse(int n) {
	if (n == 0) {
		return;
	}

	cout << n << " ";
	printNReverse(n-1);
}

int sumOfN(int n) {
	if (n == 0) {
		return 0;
	}

	return n + sumOfN(n-1);
}

int factorial(int n) {
	if (n <= 1) {
		return n;
	}

	return n * factorial(n-1);
}

void reverseAnArray_pointer(vector<int> &arr, int i, int j) {
	if (i >= j) {
		return;
	}

	swap(arr[i], arr[j]);
	reverseAnArray_pointer(arr, i+1, j-1);
}

void reverseAnArray_functional(vector<int> &arr, int ind, int n) {
	if (ind == n/2) {
		return;
	}

	swap(arr[ind], arr[n-ind-1]);
	reverseAnArray_functional(arr, ind+1, n);
}

bool checkPalindrome_pointer(vector<int> &arr, int i, int j) {
	if (i >= j) {
		return true;
	}

	if (arr[i] != arr[j]) {
		return false;
	}

	return checkPalindrome_pointer(arr, i+1, j-1);
}

bool checkPalindrome_functional(vector<int> &arr, int ind, int n) {
	if (ind >= n/2) {
		return true;
	}

	if (arr[ind] != arr[n-ind-1]) {
		return false;
	}

	return checkPalindrome_functional(arr, ind+1, n);
}

// Time :- O(2^N)
int fibonacci(int n) {
	if (n <= 1) {
		return n;
	}

	return fibonacci(n-1) + fibonacci(n-2);
}

void subsequenceTheory
(vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int ind, int n) {
	if (ind >= n) {
		vector<int> res;
		for (auto it : ds) {
			res.push_back(it);
		}
		ans.push_back(res);
		return;
	}

	// take or pick the particular element in the subsequence.
	ds.push_back(arr[ind]);
	subsequenceTheory(arr, ds, ans, ind+1, n);

	// don't take or pick the particular element in the subsequence.
	ds.pop_back();
	subsequenceTheory(arr, ds, ans, ind+1, n);
}

int main() {

	// Question 1
	// string name;
	// int n;
	// cin >> n;
	// cin >> name;
	// printNameNTimes(name, n);

	// Question 2
	// int n;
	// cin >> n;
	// printNLinearly(n);

	// Question 3
	// int n;
	// cin >> n;
	// printNReverse(n);

	// Question 4
	// int n;
	// cin >> n;
	// cout << sumOfN(n);

	// Question 6
	// int n;
	// cin >> n;
	// cout << factorial(n);

	// Question 7
	// int size;
	// cin >> size;
	// vector<int> arr(size);
	// for (int i = 0; i < size; i++) {
	// 	cin >> arr[i];
	// }
	// for (int i = 0; i < size; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
	// reverseAnArray_pointer(arr, 0, size-1);
	// for (int i = 0; i < size; i++) {
	// 	cout << arr[i] << " ";
	// }

	// Question 8
	// int size;
	// cin >> size;
	// vector<int> arr(size);
	// for (int i = 0; i < size; i++) {
	// 	cin >> arr[i];
	// }
	// for (int i = 0; i < size; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
	// reverseAnArray_functional(arr, 0, size);
	// for (int i = 0; i < size; i++) {
	// 	cout << arr[i] << " ";
	// }

	// Question 9
	// int size;
	// cin >> size;
	// vector<int> arr(size);
	// for (int i = 0; i < size; i++) {
	// 	cin >> arr[i];
	// }
	// for (int i = 0; i < size; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
	// cout << checkPalindrome_pointer(arr, 0, size-1);

	// Question 10
	// int size;
	// cin >> size;
	// vector<int> arr(size);
	// for (int i = 0; i < size; i++) {
	// 	cin >> arr[i];
	// }
	// for (int i = 0; i < size; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
	// cout << checkPalindrome_functional(arr, 0, size

	// Question 11
	// int n;
	// cin >> n;
	// for (int i = 0; i < n; i++) {
	// 	cout << fibonacci(i) << " ";
	// }
	// cout << endl;

	// Question 12
	int size;
	cin >> size;
	vector<int> arr(size);
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	vector<int> ds;
	vector<vector<int>> ans;
	subsequenceTheory(arr, ds, ans, 0, size);
	for (auto res : ans) {
		cout << "[ ";
		for (auto it : res) {
			cout << it << " ";
		}
		cout << "]" << endl;
	}

	return 0;
}