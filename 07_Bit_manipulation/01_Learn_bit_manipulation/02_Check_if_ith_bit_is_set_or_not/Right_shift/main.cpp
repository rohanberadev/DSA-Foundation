#include <bits/stdc++.h>
using namespace std;

bool is_Kth_Bit_Set(int decNum, int k) {
	return (decNum >> k) & 1;
}

int main() {
	int n, k;
	cin >> n >> k;

	bool isSet = is_Kth_Bit_Set(n, k);

	if (isSet) cout << "Yes";
	else cout << "No";

	return 0;
}