#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

vector<int> primeFactorization(int n) {
  // sieve of eratosthenes
  vector<int> spf(n+1);

  for (int i = 0; i <= n; i++) {
    spf[i] = i;
  } 
  
  for (int i = 2; i <= sqrt(n); i++) {
    if (spf[i] == i) {
      for (int j = i*i; j <= n; j+=i) {
        if (spf[j] == j) spf[j] = i;
      } 
    } 
  } 

  vector<int> ans;
  while (n != 1) {
    ans.push_back(spf[n]);
    n = n / spf[n];
  } 

  if (n != 1) ans.push_back(n);

  return ans;
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

  vector<int> ans = primeFactorization(n);

  for (auto it : ans) {
    cout << it << " ";
  }
  
  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
