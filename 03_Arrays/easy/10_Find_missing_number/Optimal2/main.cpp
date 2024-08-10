#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int findXorrN (int n) {
  if (n % 4 == 1) return 1;
  else if (n % 4 == 2) return n+1;
  else if (n % 4 == 3) return 0;
  else if (n % 4 == 0) return n;
  return 0;
}

int findMisssing(vector<int> arr) {
  int n = arr.size();
  int xorrN = findXorrN(n+1);
  int xorr = 0;

  for (int i = 0; i < n; i++) xorr = xorr ^ arr[i];

  return xorrN ^ xorr;
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
  
  int size;
  cin >> size;
  
  vector<int> arr(size);
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  cout << findMisssing(arr);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
