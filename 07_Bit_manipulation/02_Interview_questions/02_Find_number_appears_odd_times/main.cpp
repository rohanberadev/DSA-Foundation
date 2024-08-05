#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int findNumAppearsOddTimes(vector<int> &nums) {
  int n = nums.size();
  int xorr = 0;

  for (int i = 0; i < n; i++) {
    xorr = xorr ^ nums[i];  
  }

  return xorr;
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

  cout << findNumAppearsOddTimes(nums);
  
  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
