#include <bits/stdc++.h>
using namespace std;

// Time :- O(N) Space :- O(1)
int convertBinaryToDecimalIterative(string binary) {
	int n = binary.size();
	int num = 0;

	for (int i = n-1; i >= 0; i--) {
		if (binary[i] == '1') {
			int x = 1 << (n-i-1);
			num += x;
		}
	}

	return num;
}

// Time :- O(N) Space :- O(1)
int convertBinaryToDecimalRecusrive(string binary) {
	int n = binary.size();
	
	function<int(int)> solve =  [&](int ind) -> int {
		if (ind == n-1) {
			if (binary[ind] == '1') return 1;
			else return 0;
		}

		int num = solve(ind+1);
		if (binary[ind] == '1') num += 1 << (n-ind-1);

		return num;
	};	

	return solve(0);
}

int main() {

	string binary;
	cin >> binary;

	// cout << convertBinaryToDecimalIterative(binary);
	cout << convertBinaryToDecimalRecusrive(binary);

	return 0;
}