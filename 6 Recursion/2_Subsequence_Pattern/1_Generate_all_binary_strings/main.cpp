#include <bits/stdc++.h>
using namespace std;

void generateBinaryStrings_util(string s, int ind, int n) {
	if (ind == n) {
		cout << s << endl;
		return;
	}

	if (s[ind-1] == '0') {
		generateBinaryStrings_util(s+"0", ind+1, n);

		generateBinaryStrings_util(s+"1", ind+1, n);
	}

	if (s[ind-1] == '1') {
		generateBinaryStrings_util(s+"0", ind+1, n);
	}
}

void generateBinaryStrings(int n) {
	generateBinaryStrings_util("0", 1, n);
	generateBinaryStrings_util("1", 1, n);
}

int main() {
	int n;
	cin >> n;

	generateBinaryStrings(n);
	return 0;
}