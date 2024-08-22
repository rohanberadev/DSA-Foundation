#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int linearSearch(vector<int> arr, int target) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) return i;
  }
  return -1;
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
  
  int n, target;
  cin >> n >> target; 
  
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << linearSearch(arr,target);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
