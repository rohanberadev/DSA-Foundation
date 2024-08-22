#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

bool checkArraySorted(vector<int> &arr) {
  int n = arr.size();

  for (int i = 1; i < n; i++) {
    if (arr[i-1] > arr[i]) return false;
  }

  return true;
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

  bool isSorted = checkArraySorted(arr);
  if (isSorted) cout << "Array is sorted!";
  else cout << "Array is not sorted!";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
