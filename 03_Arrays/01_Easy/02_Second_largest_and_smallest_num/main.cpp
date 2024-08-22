#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int findSecondLargestNum(vector<int> &arr) {
  int n = arr.size();
  int first = INT_MIN;
  int second = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (first < arr[i]) {
      second = first;
      first = arr[i];
    } else if (second < arr[i] && first != arr[i]) {
      second = arr[i];
    }
  }

  return second;
}

int findSecondSmallestNum(vector<int> &arr) {
  int n = arr.size();
  int first = INT_MAX;
  int second = INT_MAX;

  for (int i = 0; i < n; i++) {
    if (first > arr[i]) {
      second = first;
      first = arr[i];
    } else if (second > arr[i] && first != arr[i]) {
      second = arr[i];
    }
  }

  return second;
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
  
  cout << "Second Largest Number: ";
  cout << findSecondLargestNum(arr) << endl;

  cout << "Second Largest Number: ";
  cout << findSecondSmallestNum(arr);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
