#include<bits/stdc++.h>
using namespace std;

void generateParanthesis_util(string s, int pos, int open, int close, int n) {
	if (pos == n*2) {
		cout << s << endl;
		return;
	}

	if (open < n) {
		generateParanthesis_util(s+"(", pos+1, open+1, close, n);
	}

	if (close < open) {
		generateParanthesis_util(s+")", pos+1, open, close+1, n);
	}

}

void generateParanthesis(int n) {
	generateParanthesis_util("", 0, 0, 0, n);
}

int main() {
	int n;
	cin >> n;

	generateParanthesis(n);

	return 0;
}