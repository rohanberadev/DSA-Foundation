#include <bits/stdc++.h>
using namespace std;

void combinationLetters_util
(vector<string> &str, int ind, int len, int n, string &ds, vector<string> &ans, bool sel) {

	if (len == 0) {
		ans.push_back(ds);
		return;
	}

	if (ind >= n) return;

	for (int i = 0; i < str[ind].size(); i++) {
		if (sel) break;

		ds.push_back(str[ind][i]);
		combinationLetters_util(str, ind, len-1, n, ds, ans, true);
		ds.pop_back();
	}
	
	combinationLetters_util(str, ind+1, len, n, ds, ans, false);
}

vector<string> combinationLetters(string digits) {
	vector<string> ans;

	if (digits.size() == 0) {
		return ans;
	}

	unordered_map<char, string> mpp;
	mpp['2'] = "abc"; 
	mpp['3'] = "def"; 
	mpp['4'] = "ghi"; 
	mpp['5'] = "jkl"; 
	mpp['6'] = "mno"; 
	mpp['7'] = "pqrs"; 
	mpp['8'] = "tuv"; 
	mpp['9'] = "wxyz"; 

	vector <string> str;
	for (int i = 0; i < digits.size(); i++) {
		str.push_back(mpp[digits[i]]);
	}

	string ds  = "";
	combinationLetters_util(str, 0, digits.size(), str.size(), ds, ans, false);

	return ans;
}

int main() {

	string digits;
	cin >> digits;

	vector<string> ans = combinationLetters(digits);

	for (auto it : ans) {
		cout << it << endl;
	}

	return 0;
}