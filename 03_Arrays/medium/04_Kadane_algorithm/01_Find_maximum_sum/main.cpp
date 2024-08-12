#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

long long kadaneAlgorithm(vector<int> arr) {
  int n = arr.size();
  long long maxi = LONG_MIN;
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    sum += arr[i];
    
    if (maxi < sum) maxi = sum;

    if (sum < 0) sum = 0;
  }
  
  return maxi; 
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

  cout << kadaneAlgorithm(arr);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
