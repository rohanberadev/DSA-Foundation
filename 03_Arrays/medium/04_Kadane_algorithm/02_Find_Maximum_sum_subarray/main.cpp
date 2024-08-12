#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

pair<int,int> kadaneAlgorithm(vector<int> arr) {
  int n = arr.size();
  long long maxi = LONG_MIN;
  long long sum = 0;
  
  int start = -1;
  int end = -1;
  
  int startTemp = 0;

  for (int i = 0; i < n; i++) {
    if (sum == 0) startTemp = i;

    sum += arr[i];
    
    if (maxi < sum) {
      start = startTemp;
      end = i;
      maxi = sum;
    }

    if (sum < 0) sum = 0;

  }
  
  return {start, end}; 
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
  
  pair<int, int> ans = kadaneAlgorithm(arr);

  cout << ans.first << " " << ans.second << endl;

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
