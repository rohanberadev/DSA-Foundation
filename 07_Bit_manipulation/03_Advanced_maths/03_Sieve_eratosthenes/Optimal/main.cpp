#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

// Time :- O(N + (N * Log(Log(N))) + N) Space :- O(N)
void sieveOfEratosthenes(int n) {
  // Time :- O(N)
  vector<int> primes(n+1, 1);
  
  // Time :- O(N * Log(Log(N)))
  // Prime harmonic sieves.
  for (int i = 2; i <= sqrt(n); i++) {
    // number is prime.
    if (primes[i] == 1) {
      // starts with 2 * 2, 3 * 3, 4 * 4, 5 * 5 
      for (int j = i*i; j <= n; j += i) primes[j] = 0;
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
