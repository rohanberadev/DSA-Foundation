#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int removeDuplicates(vector<int> &arr) {
  sort(arr.begin(), arr.end());

  int n = arr.size();

  int ind = 0;
  while (ind < n-1 && arr[ind] != arr[ind+1]) ind++;

  if (ind >= n) return n;

  int i = ind + 1;
  while (i < n) {
    if (arr[ind] != arr[i]) {
      ind++;
      swap(arr[i], arr[ind]);
    }
    i++;
  }

  return ind+1;
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

  int n = removeDuplicates(arr);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
