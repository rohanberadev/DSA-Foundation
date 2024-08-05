#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string &s, vector<string> &wordDict) {
	int n = s.size();

	function<bool(string)> checkPresent = [&](string word) -> bool {
		for (auto it : wordDict) {
			if (it == word) return true;
		}
		return false;
	};

	function<bool(int, string)> solve = [&](int ind, string word) -> bool {
		if (ind >= n) return true;

		for (int i = ind; i < n; i++) {
			word += s[i];
			if (checkPresent(word)) {

				if (solve(i+1, "")) return true;
				
			}
		}

		return false;
	};

	string word = "";
	return solve(0, word);
}

int main() {

	string s;
	int n;
	cin >> s >> n;

	vector<string> wordDict(n);
	for (int i = 0; i < n; i++) {
		cin >> wordDict[i];
	}

	bool isSolved = wordBreak(s, wordDict);

	cout << endl;

	if (isSolved) cout << "Found!";
	else cout << "Not found!";

	return 0;
}