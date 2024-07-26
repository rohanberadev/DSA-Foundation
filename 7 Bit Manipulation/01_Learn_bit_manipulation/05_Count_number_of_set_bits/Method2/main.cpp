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

int countSetBits(int num) {
	if (num == 0) return 0;

	num = num & (num-1);
	int count = countSetBits(num);
	return count+1;
}

int main() {
	int n;
	cin >> n;

	cout << decimalToBinary(n) << endl;

	cout << countSetBits(n);

	return 0;
}