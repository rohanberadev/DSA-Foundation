#include <bits/stdc++.h>
using namespace std;

// Time :- 0(log(N) + N) Space :- O(log(N))
string convertDecimalToBinaryIterative(int n) {
	string s  = "";

	while (n != 0) {
		int x = n % 2;
		n /= 2;
		s += to_string(x);
	}

	// reverse
	int i = 0;
	int j = s.size()-1;
	while (i < j) swap(s[i++], s[j--]);

	return s;
}

// Time :- 0(log(N)) Space :- O(log(N))
string convertDecimalToBinaryRecursive(int n) {
	string s = "";

	function<void()> solve = [&]() -> void {
		if (n == 0) return;

		int x = n % 2;
		n /= 2;
		solve();
		s += to_string(x);
	};

	solve();
	return s;
}

int main() {
	int n;
	cin >> n;

	cout << convertDecimalToBinaryIterative(n);

	return 0;
}