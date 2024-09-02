#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int divideTwoNumber(int dividend, int divisor) {
  if (dividend == divisor) {
    return 1;
  }

  int sign = +1;

  if (dividend < 0) {
    sign = sign * -1;
  }

  if (divisor < 0) {
    sign = sign * -1;
  }

  long n = abs(dividend);
  long d = abs(divisor);
  long ans = 0;

  while (n >= d) {
    int i = 0;
    while (n - d * (1L << (i + 1)) >= d) {
      i++;
    }
    n = n - (d * (1L << i));
    ans = ans + (1L << i);
  }

  if (ans * sign < INT_MIN) {
    return INT_MIN;
  }

  if (ans * sign > INT_MAX) {
    return INT_MAX;
  }

  return ans * sign;
}

int main() {

  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input.txt file!";
    return 1;
  }

  streambuf *cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());

  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output.txt file!";
    return 1;
  }

  streambuf *coutbuf = cout.rdbuf();
  cout.rdbuf(outfile.rdbuf());

  int n, d;
  cin >> n >> d;

  cout << divideTwoNumber(n, d);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
