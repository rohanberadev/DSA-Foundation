#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

vector<int> count_NGE(vector<int> arr, int queries, vector<int> indices) {
  int n = arr.size();
  vector<int> ans;

  for (int q = 0; q < queries; q++) {
    int cnt = 0;
    int num = arr[indices[q]];
    for (int i = n-1; i > indices[q]; i--) {
      if (arr[i] > num) cnt++;
    }
    ans.push_back(cnt);
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
  for (int i = 0; i < size; i++) cin >> arr[i];
  
  int queries;
  cin >> queries;
  
  vector<int> indices(queries);
  for (int i = 0; i < queries; i++) cin >> indices[i];

  vector<int> ans = count_NGE(arr, queries, indices);
  for (auto it : ans) cout << it << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
