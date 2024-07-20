#include <bits/stdc++.h>
using namespace std;

int atoieasy_recursive(string s, int ind, int n, int num, int sign) {
	if (ind >= n) {
		return num * sign;
	}

	if (s[ind] == '-') {
		return atoieasy_recursive(s, ind+1, n, num, -1);
	}
	else if (s[ind] == '+') {
		return atoieasy_recursive(s, ind+1, n, num, +1);
	}
	else {
		num *= 10;
		num += int(s[ind] - '0');	
		return atoieasy_recursive(s, ind+1, n, num, sign);
	}
}	

bool checkIfNum(char c) {
	return c >= '0' && c <= '9';
}

// medium
int atoi_iterative(string s, int n) {
	int ind = 0;
	while (ind < n && s[ind] == ' ') {
		ind++;
	}

	if (ind == n) {
		return 0;
	}	

	int sign = +1;
	int MAX = INT_MAX;
	int MIN = INT_MIN;
	int num = 0;

	if (s[ind] == '-') {sign = -1; ind++;}
	else if (s[ind] == '+') {sign = +1; ind++;}

	while (ind < n) {
		if (s[ind] == ' ') continue;
		if (!checkIfNum(s[ind])) break;

		num *= 10;
		num += int(s[ind] - '0');

		if (num*sign < MIN) num = MIN;
		else if (num*sign > MAX) num = MAX;

		ind++;
	}

	return num*sign;
}

int atoi_recursive(string s, int ind, int n, int num, int sign) {
	if (ind >= n) {
		if (sign == 0) sign = 1;
		return num * sign;
	}

	if (s[ind] == ' ') return atoi_recursive(s, ind+1, n, num, sign);

	if ((s[ind] == '+' || s[ind] == '-') && sign != 0) return atoi_recursive(s, n, n, num, sign);

	if (s[ind] == '+' || s[ind] == '-') {
		if (s[ind] == '+') return atoi_recursive(s, ind+1, n, num, +1);
		if (s[ind] == '-') return atoi_recursive(s, ind+1, n, num, -1);
	}


	if (!checkIfNum(s[ind])) return atoi_recursive(s, n, n, num, sign);
	else {
		num *= 10;
		num += int(s[ind] - '0');
		return atoi_recursive(s, ind+1, n, num, sign);
	}
}

int main() {
	string s;
	cin >> s;
	int num = 0;
	int sign = +1;
	// cout << atoieasy_recursive(s, 0, s.size(), num, sign) << endl;
	// cout << atoi_iterative(s, s.size());
	cout << atoi_recursive(s, 0, s.size(), 0, 0);

	return 0;
}