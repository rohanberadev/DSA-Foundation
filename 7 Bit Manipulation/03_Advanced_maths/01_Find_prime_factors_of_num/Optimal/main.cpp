#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;



// Time :- O(sqrt(N) * log(N))
// Space :- O(1)
vector<int> findPrimeFactors(int n) {
  vector<int> ans;

  for (int i = 2; i < sqrt(n); i++) {
    if (n % i == 0) {
      ans.push_back(i);
      while (n % i == 0) n = n / i; 
    }
  } 
  
  // this means n only divisible by itself.
  if (n != 1) ans.push_back(n);

  return ans;
}

int main() {
  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input file";
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

  vector<int> ans = findPrimeFactors(n);
  
  for (auto it : ans) {
    cout << it << " ";
  } 

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);
  
  infile.close();
  outfile.close();

  return 0;
}

