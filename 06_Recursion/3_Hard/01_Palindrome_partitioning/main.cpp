#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string &str, int i, int j) {
	int l = i;
	int r = j;
	while (l < r) {
		if (str[l++] != str[r--]) return false;
	}

	return true;
}

void portitioningPalindrome_util
(string &str, int ind, int n, vector<string> &path, vector<vector<string>> &ans) {

	if (ind == n) {
		ans.push_back(path);
		return;
	}

	for (int i = ind; i < n; i++) {
		if (checkPalindrome(str, ind, i)) {
			int lenOfSubstring = i - ind + 1;
			path.push_back(str.substr(ind, lenOfSubstring));
			portitioningPalindrome_util(str, i+1, n, path, ans);
			path.pop_back();
		}
	}
}

vector<vector<string>> portitioningPalindrome(string &str) {
	vector<vector<string>> ans;
	vector<string> path;
	portitioningPalindrome_util(str, 0, str.size(), path, ans);

	return ans;
}

int main() {

	string str;
	cin >> str;

	vector<vector<string>> ans = portitioningPalindrome(str);

	for (auto res : ans) {   
		cout << "[ ";                                       
		for (auto it : res) {
			cout << it << " ";
		}
		cout << "]" << endl;
	}

	return 0;
}