#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int xorFrom1ToN(int n) {
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n+1;
  if (n % 4 == 3) return 0;
  if (n % 4 == 0) return n;

  return 0;
} 

int xorFromLtoR(int l, int r) {
  int oneToL = xorFrom1ToN(l-1);
  int oneToR = xorFrom1ToN(r);
  int LtoR = oneToL ^ oneToR;
  return LtoR;
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


  int l, r;
  cin >> l >> r;
  
  cout << xorFromLtoR(l, r);
  
  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
