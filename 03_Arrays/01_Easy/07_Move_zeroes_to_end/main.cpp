#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void moveZeroesToEnd(vector<int> &arr) {
  int n = arr.size();
  int i = 0;
  while (i < n && arr[i] != 0) {
    i++;
  }

  if (i == n) return;
  
  for (int j = i+1; j < n; j++) {
    if (arr[j] != 0) swap(arr[i++], arr[j]);
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
  
  int size;
  cin >> size;
  
  vector<int> arr(size);
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  moveZeroesToEnd(arr);

  for (int i = 0; i < size; i++) cout << arr[i] << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
