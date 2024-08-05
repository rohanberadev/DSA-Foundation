#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void bubbleSort(vector<int> &arr) {
  int n = arr.size();

  for (int i = n-1; i >= 0; i--) {
    bool isSwap = false;

    for (int j = 1; j <= i; j++) {
      if (arr[j-1] > arr[j]) {
        swap(arr[j-1], arr[j]);
        isSwap = true;
      }
    }

    if (!isSwap) break;
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
