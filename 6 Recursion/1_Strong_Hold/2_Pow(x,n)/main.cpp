#include<bits/stdc++.h>
using namespace std;

// Time :- O(N)
int pow_iterative(int x, int n) {
	int ans = 1;
	if (n == 0) {
		return 1;
	}

	for (int i = 1; i <= n; i++) {
		ans *= x;
	}

	return ans;
}

// Time :- O(log N)
int pow_recursive(int x, int n) {
	int ans = 1;
	if (n == 0) {
		return 1;
	}

	if (n%2 == 0) {
		x = x * x;
		n /= 2;
	} else {
		ans *= x;
		n -= 1;
	}

	ans *= pow_recursive(x, n);

	return ans;
}

int main() {
	int x;
	int n;
	cin >> x;
	cin >> n;
	cout << pow_iterative(x, n) << endl;
	cout << pow_recursive(x, n);
	return 0;
}