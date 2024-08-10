#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int findMissing(vector<int> arr) {
  int n = arr.size();
  int sn = (n + 1) * ((n + 1) + 1) / 2;
  int s = 0;

  for (int i = 0; i < n; i++) s += arr[i];

  return sn - s;
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

  cout << findMissing(arr);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
