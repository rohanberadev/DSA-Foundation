#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int divideTwoNumber(int dividend, int divisor) {
  if (dividend == divisor) return 1;

  int sign = -1;
  
  if (dividend < 0 && divisor < 0) sign = +1;
  else if (dividend >= 0 && divisor >= 0) sign = +1;
  
  long n = dividend;
  long d = divisor;
  long ans = 0;

  while (n >= d) {
    int i = 0;
    while ((d * (1L << i)) >= n) i++;
    n = n - (d * (1L << i));
    ans = ans + (1L << i);
  }

  if (ans == (1L << 31) && sign == +1) return INT_MAX;
  if (ans == (1L << 31) && sign == -1) return INT_MIN;

  return ans * sign;
}

int main() {

  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input.txt file!";
    return 1;
  }

  streambuf* cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());

  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output.txt file!";
    return 1;
  }

  streambuf* coutbuf = cout.rdbuf();
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
