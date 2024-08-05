#include <bits/stdc++.h>
using namespace std;

bool checkNum(char c) {
	return c >= '0' && c <= '9';
}

int atoiIterative(string s, int n) {
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
		if (!checkNum(s[ind])) break;

		num *= 10;
		num += int(s[ind] - '0');

		if (num*sign < MIN) return MIN;
		else if (num*sign > MAX) return MAX;

		ind++;
	}

	return num*sign;
}

int myAtoi(string s) {
	return atoiIterative(s, s.size());
}

int main() {
	string s;
	cin >> s;

	cout << myAtoi(s);

	return 0;
}