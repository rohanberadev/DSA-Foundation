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

int remove_last_set_bit(int num) {
	int i = 0;
	while (!(num & (1 << i))) {
		i++;
	}

	num = num & ~(1 << i);
	return num;
}

int main() {

	int n;
	cin >> n;

	cout << n << endl;
	cout << decimalToBinary(n) << endl << endl;

	n = remove_last_bit(n);
	cout << n << endl;
	cout << decimalToBinary(n);

	return 0;
}