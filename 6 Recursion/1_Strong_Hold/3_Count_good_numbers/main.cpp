#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

/*
A digit string is good if the digits (0-indexed) at even indices are even and 
the digits (0, 2, 4, 6, 8) at odd indices are prime (2, 3, 5, or 7).
*/

ll power(ll x, ll n) {
	ll ans = 1;
	
	if (n == 0) return 1;

	if (n%2 == 0) {
		x = (x * x) % MOD;
		n /= 2;
	} else {
		ans = (ans * x) % MOD;
		n -= 1;
	}

	ans *= power(x, n);
	return ans % MOD;
}

int countGoodNumbers(int n) {
	ll even = (n / 2) + (n % 2);
	ll odd = n / 2;

	int ans = (power(5, even) * power(4, odd)) % MOD;

	return ans;
}

int main() {
	int n;
	cin >> n;
	cout << countGoodNumbers(n);
	return 0;
}