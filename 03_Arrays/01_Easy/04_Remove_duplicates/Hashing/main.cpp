#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int removeDuplicates(vector<int> &arr) {
  set<int> s;
  int n = arr.size();

  for (int i = 0; i < n; i++) {
    s.insert(arr[i]); 
  }  
  
  int j = 0;
  for (int x : s) {
    arr[j++] = x;
  }

  return j;
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
