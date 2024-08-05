#include <bits/stdc++.h>
using namespace std;

bool check_Odd_Or_Even(int num) {
	return num & 1;
}

int main() {

	int n;
	cin >> n;

	bool isOddOrEven = check_Odd_Or_Even(n);

	if (isOddOrEven) cout << "Odd";
	else cout << "Even";

	return 0;
}