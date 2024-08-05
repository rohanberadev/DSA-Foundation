#include <bits/stdc++.h>
using namespace std;

bool checkNum(char c) {
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

int atoitRecusrive(string s, int ind, int n, long num, int sign) {
	if (ind >= n) return num * sign;

	// removing leading zeroes.
	if (s[ind] == ' ' && sign == 0) return atoitRecusrive(s, ind+1, n, num, sign);

	// taking +ve sign if it is not there.
	if (s[ind] == '+') {
		if (sign == 0) return atoitRecusrive(s, ind+1, n, num, +1);
		else atoitRecusrive(s, n, n, num, sign);
	}

	// taking -ve sign if it is not there.
	if (s[ind] == '-') {
		if (sign == 0) return atoitRecusrive(s, ind+1, n, num, -1);
		else atoitRecusrive(s, n, n, num, sign);
	}

	// checking if the character is a number.
	if (!checkNum(s[ind])) return atoitRecusrive(s, n, n, num, sign);

	// character reaches here if it is a number.
	num = num*10 + (s[ind] - '0');
	// if there is not sign ultil here then it is +ve number.
	if (sign == 0) sign = +1;

	// if number crosses the int boundary
	if (num*sign < INT_MIN) return INT_MIN;
	if (num*sign > INT_MAX) return INT_MAX;

	return atoitRecusrive(s, ind+1, n, num, sign);
}

int myAtoi(string s) {
	return atoitRecusrive(s, 0, s.size(), 0, 0);
}

int main() {
	string s;
	cin >> s;

	cout << myAtoi(s);

	return 0;
}