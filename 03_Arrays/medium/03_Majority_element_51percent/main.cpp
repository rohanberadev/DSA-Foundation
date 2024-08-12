#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
#include <vector>
using namespace std;

// Time :- O(N) 
// Space :- O(N)
int findMajority_hashing(vector<int> arr) {
  int n = arr.size();
  map<int, int> mpp;

  for (int i = 0; i < n; i++) {
    if (mpp.find(arr[i]) != mpp.end()) {
      mpp[arr[i]]++;
    }
    else {
      mpp[arr[i]] = 1;
    }
  }

  for (auto it : mpp) {
    if (it.second > n/2) return it.first; 
  }
  
  return -1;
}

// Moore's Voting Algorithm
// Time :- O(N)
// Space :- O(1)
int findMajority_optimal(vector<int> arr) {
  int n = arr.size();
  
  int elem = -1;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    if (cnt == 0) {
      elem = arr[i];
      cnt = 1;
    }
    else if (elem == arr[i]) cnt++;
    else if (elem != arr[i]) cnt--;
  }
  
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == elem) cnt++;
  }

  if (cnt > n/2) return elem;
  else return -1;
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

  cout << "Brute: " << findMajority_hashing(arr) << endl;
  cout << "Optimal: " << findMajority_optimal(arr) << endl;

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
