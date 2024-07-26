#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n) {
	string bin = "";

	function<void()> solve = [&]() -> void {
		if (n == 0) return;

		int x = n % 2;
		n /= 2;
		solve();

		bin += to_string(x);
	};

	solve();

	return bin;
}

int clear_kth_bit(int num, int k) {
	return  num & ~(1 << k);
}

int main() {

	int n, k;
	cin >> n >> k;

	string bin = decimalToBinary(n);

	cout << n << endl;
	cout << bin << endl << endl;

	n = clear_kth_bit(n, k);
	bin = decimalToBinary(n);

	cout << n << endl;
	cout << bin << endl;

	return 0;
}