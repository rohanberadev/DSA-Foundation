#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

// Time :- O((N+1) + N)
void sieveOfEratosthenes(int n) {
  vector<int> primes(n+1, 1);

  for (int i = 2; i <= n; i++) {
    // number is prime.
    if (primes[i] == 1) {
      for (int j = i*2; j <= n; j += i) primes[j] = 0;
    }
  }

  for (int i = 2; i <= n; i++) {
    if (primes[i] == 1) cout << i << " ";
  }
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
  
  int n;
  cin >> n;

  sieveOfEratosthenes(n);
  
  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
