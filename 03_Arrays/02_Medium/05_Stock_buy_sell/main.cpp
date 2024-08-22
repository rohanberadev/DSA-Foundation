#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int maxProfit_brute(vector<int> arr) {
  int n = arr.size();
  int maxPro = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      maxPro = max(maxPro, arr[j]-arr[i]);
    }
  }
  return maxPro;
}

int maxProfit_optimal(vector<int> arr) {
  int n = arr.size();
  int minPrice = INT_MAX;
  int maxPro = 0;

  for (int i = 0; i < n; i++) {
    minPrice = min(arr[i], minPrice);
    maxPro = max(arr[i] - minPrice, maxPro);
  }

  return maxPro;
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

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
