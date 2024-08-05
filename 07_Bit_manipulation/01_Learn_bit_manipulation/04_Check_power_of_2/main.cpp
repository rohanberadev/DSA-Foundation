#include <bits/stdc++.h>
using namespace std;

bool checkPowerOf2(int num) {
	return ((num-1) & num) == 0;
}

int main() {	

	int n;
	cin >> n;

	if (checkPowerOf2(n)) cout << "Yes";
	else cout << "No"; 

	return 0;
}