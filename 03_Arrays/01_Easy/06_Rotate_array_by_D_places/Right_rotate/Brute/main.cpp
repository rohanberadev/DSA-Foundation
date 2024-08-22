#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void rightRotate(vector<int> &arr, int d) {
  int n = arr.size();
  d = d % n;
  
  vector<int> temp(d);

  for (int i = n-d; i < n; i++) {
    // i - (n - d) = i - n + d
    temp[i-n+d] = arr[i]; 
  }

  for (int i = n-d-1; i >= 0; i--) {
    arr[i+d] = arr[i];
  }

  for (int i = 0; i < d; i++) {
    arr[i] = temp[i];
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
  
  int size, d;
  cin >> size >> d;
  
  vector<int> arr(size);
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  rightRotate(arr, d);
    
  for (int i = 0; i < size; i++) cout << arr[i] << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
