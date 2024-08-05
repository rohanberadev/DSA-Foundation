#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

vector<vector<int>> powerSet(vector<int> &nums) {
  vector<vector<int>> ans; 
  int n = nums.size();

  for (int ind = 0; ind < (1 << n); ind++) {
    vector<int> res;

    for (int i = 0; i < n; i++) {
      if (ind & (1 << i)) res.push_back(nums[i]);
    }

    ans.push_back(res);
  }

  return ans;
}  

int main() {

  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input.txt file!";
    return 1;
  }

  streambuf* cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());

  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output.txt file!";
    return 1;
  }

  streambuf* coutbuf = cout.rdbuf();
  cout.rdbuf(outfile.rdbuf());


  int size;
  cin >> size;
  
  vector<int> nums(size);
  for (int i = 0; i < size; i++) {
    cin >> nums[i];
  }
  
  vector<vector<int>> ans = powerSet(nums);
  for (auto res : ans) {
    for (auto it : res) {
      cout << it << " ";
    } 
    cout << endl;
  }
  
  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
