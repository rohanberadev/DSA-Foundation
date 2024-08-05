#include <bits/stdc++.h>
using namespace std;

vector<string> addOperators(string s, int target) {
	int n = s.size();
	vector<string> ans;

	function<void(int, long, long, string)> backtrack = 
	[&](int ind, long res, long prevNum, const string path) -> void {

		if (ind == n) {
			if (res == target) ans.push_back(path);
			return;
		}

		string numStr = "";
		long num = 0;

		for (int i = ind; i < n; i++) {
			// it will allow numbers like :- 0, 10, 20, etc.
			// it will not allow numbers like :- 00, 01, 02, etc.
			if (i > ind && s[ind] == '0') break;

			// current number in integer form.
			num = num * 10 + (s[i] - '0');
			// current number in string form.
			numStr += s[i];

			if (i == 0) {
				backtrack(i+1, num, num, numStr);
			}
			else {
				// addition
				backtrack(i+1, res+num, +num, path+"+"+numStr);
				// subtraction
				backtrack(i+1, res-num, -num, path+"-"+numStr);
				// mulplication
				backtrack(i+1, res-prevNum+(prevNum*num), prevNum*num, path+"*"+numStr);
			}
		}
	};

	backtrack(0, 0, 0, "");

	return ans;
}

int main() {

	string num;
	int target;
	cin >> num >> target;

	vector<string> ans = addOperators(num, target);

	if (ans.empty()) cout << "Not found!" << endl << endl;
	else cout << "Found!" << endl << endl;

	for (auto it : ans) {
		cout << it << endl;
	}

	return 0;
}