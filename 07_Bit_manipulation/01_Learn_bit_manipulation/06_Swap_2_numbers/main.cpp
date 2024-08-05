#include<bits/stdc++.h>
using namespace std;

void swapNumbers(int &a, int &b) {
	//  a = a ^ b
	a = a ^ b;
	// b = a ^ b ^ b = a 
	b = a ^ b;
	// a = a ^ b ^ a = a
	a = a ^ b;
}

int main() {

	int a, b;
	cin >> a >> b;

	cout << a << " " << b << endl;
	swapNumbers(a, b);
	cout << a << " " << b;

	return 0;
}