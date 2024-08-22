#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void leftRotateByOne(vector<int> &arr) {
  int n = arr.size();
  int temp = arr[0];
  for (int i = 0; i < n-1; i++) {
    arr[i] = arr[i+1];
  }
  arr[n-1] = temp;
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

  leftRotateByOne(arr);
    
  for (int i = 0; i < size; i++) cout << arr[i] << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
