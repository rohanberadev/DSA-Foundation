#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void bubbleSort_util(vector<int> &arr, int n) {
  if (n == 0) return;

  for (int i = 1; i <= n; i++) {
    if (arr[i-1] > arr[i]) swap(arr[i-1], arr[i]);
  }

  bubbleSort_util(arr, n-1);
}

void bubbleSort(vector<int> &arr) {
  bubbleSort_util(arr, arr.size()-1);
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

  bubbleSort(arr);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
