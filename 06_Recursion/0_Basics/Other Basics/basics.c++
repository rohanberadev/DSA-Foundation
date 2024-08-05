#include <bits/stdc++.h>
using namespace std;

int countZeroesFromArray_1(int arr[], int n) {
	int count = 0;
	if (n == 0) {
		return count;
	}

	if (arr[n-1] == 0) {
		count += 1;
	}

	count += countZeroesFromArray_1(arr, n-1);

	return count;
}

int factorial(int n) {
	if (n <= 1) {
		return n;
	}

	return n * factorial(n-1);
}

int findFirstIndexOfTarget(int arr[], int ind, int n, int target) {
	if (ind == n) {
		return -1;
	}

	if (arr[ind] == target) {
		return ind;
	}

	return findFirstIndexOfTarget(arr, ind+1, n, target);
}

int findLastIndexOfTarget(int arr[], int n, int target) {
	if (n == 0) {
		return -1;
	}

	if (arr[n-1] == target) {
		return n-1;
	}

	return findLastIndexOfTarget(arr, n-1, target);
}

string replaceOccurences(string s, int ind, int n, char target) {
	string newS = "";
	if (ind == n) {
		return "";
	}

	if (s[ind] != target) {
		newS = newS + s[ind]; 
	} else {
		newS += "";
	}

	newS += replaceOccurences(s, ind+1, n, target);

	return newS;
}

string replacePIString(string s, int ind, int n) {
	string newS = "";
	if (ind == n) {
		return "";
	}

	if (s.substr(ind, 2) == "pi") {
		newS += "3.14";
		ind += 2;
	} else {
		newS += s[ind];
		ind += 1;
	};

	newS += replacePIString(s, ind, n);

	return newS;
}

int sumOfArray(int arr[], int n) {
	int sum = 0;
	if (n == 0) {
		return sum;
	} else {
		sum += arr[n-1];
	}

	sum += sumOfArray(arr, n-1);

	return sum;
}

int main() {

	// Question 1
	// int size;
	// cin >> size;
	// int arr[size];
	// for (int i = 0; i < size; i++) {
	// 	cin >> arr[i];
	// }
	// for (int i = 0; i < size; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
	// int count = countZeroesFromArray_1(arr, size);
	// cout << count;

	// Question 2
	// int n;
	// cin >> n;
	// cout << factorial(n); 

	// Question 3
	// int size;
	// cin >> size;
	// int arr[size];
	// for (int i = 0; i < size; i++) {
	// 	cin >> arr[i];
	// }
	// for (int i = 0; i < size; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
	// cout << findFirstIndexOfTarget(arr, 0, size, 4);

	// Question 4
	// int size;
	// cin >> size;
	// int arr[size];
	// for (int i = 0; i < size; i++) {
	// 	cin >> arr[i];
	// }
	// for (int i = 0; i < size; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
	// cout << findLastIndexOfTarget(arr, size, 4);

	// Question 5
	// int size;
	// cin >> size;
	// string s;
	// cin >> s;
	// char target;
	// cin >> target;
	// cout << replaceOccurences(s, 0, size, target);

	// Question 6
	// string s;
	// cin >> s;
	// cout << replacePIString(s, 0, s.size());

	// Question 7
	// int size;
	// cin >> size;
	// int arr[size];
	// for (int i = 0; i < size; i++) {
	// 	cin >> arr[i];
	// }
	// for (int i = 0; i < size; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
	// cout << sumOfArray(arr, size);

	return 0;
}