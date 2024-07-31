#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int fibonacci(int n) {
  if (n <= 1) return n;
  return fibonacci(n-1) + fibonacci(n-2);
} 

int main() {
  
  ifstream infile("inputf.in");
  if (!infile.is_open()) {
    cerr << "Error opening input file.";
    return 1;
  }

  ofstream outfile("outputf.in");
  if (!outfile.is_open()) {
    cerr << "Error opening outfile file.";
  }
  
  streambuf* coutbuf = cout.rdbuf(); 
  cout.rdbuf(outfile.rdbuf());

  int n;
  infile >> n;

  if (infile.fail()) { // Check for input errors
      cerr << "Error reading from input file." << endl;
      return 1;
  }

  cout << fibonacci(n);

  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
} 
