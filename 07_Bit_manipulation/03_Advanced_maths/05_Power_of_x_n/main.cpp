#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

double power(double x, int n) {
  double ans = 1;

  while (n > 0) {
    if (n % 2 == 0) {
      x = x * x;
      n = n / 2;
    } else {
      ans = ans * x;
      n = n - 1;
    }
  }

  return ans;
}

double myPow(double x, int n) {
  if (n < 0) return 1/power(x, n*-1);
  else return power(x, n);
}

int main() {
  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input file.";
    return 1;
  } 

  streambuf* cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());

  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output file.";
    return 1;
  }
  
  streambuf* coutbuf = cout.rdbuf();
  cout.rdbuf(outfile.rdbuf());

  double x;
  int n;
  cin >> x >> n;

  cout << myPow(x, n) << endl;

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
