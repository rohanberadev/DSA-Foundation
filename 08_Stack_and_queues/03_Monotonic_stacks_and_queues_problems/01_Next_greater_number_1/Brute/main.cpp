#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

vector<int> nextGreaterNumber(vector<int> arr) {
  int n = arr.size();
  vector<int> ans;

  for (int i = 0; i < n; i++) {
    int res = -1;
    for (int j = i+1; j < n; j++) {
      if (arr[j] > arr[i]) {
        res = arr[j];
        break;
      }
    }
    ans.push_back(res);
  }

  return ans;
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

  vector<int> ans = nextGreaterNumber(arr);

  for (auto it : ans) {
    cout << it << " ";
  }
  
  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
