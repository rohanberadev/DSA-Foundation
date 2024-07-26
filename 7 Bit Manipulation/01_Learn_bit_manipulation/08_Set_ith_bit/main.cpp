#include <bits/stdc++.h>
using namespace std;

int set_kth_bit(int num, int k) {
	return num | (1 << k);
}

int main() {

	int n, k;
	cin >> n >> k;

	cout << set_kth_bit(n, k);

	return 0;
}
