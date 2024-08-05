#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void insertionSort_util(vector<int> &arr, int i) {
  if (i == arr.size()) return;

  int j = i-1;
  while (j >= 0 && arr[j] > arr[j+1]) {
    swap(arr[j], arr[j+1]);
    j--;
  }

  insertionSort_util(arr, i+1);
}

void insertionSort(vector<int> &arr) {
  insertionSort_util(arr, 1); 
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

  insertionSort(arr);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  
  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
