#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>  
using namespace std;

pair<int, int> find2NumAppearsOddTimes(vector<int> &nums) {
  int n = nums.size();
  int xorr = 0;

  for (int i = 0; i < n; i++) {
    xorr = xorr ^ nums[i];
  }

  // geting the right most set bit;
  int rightSetBit = (xorr ^ (xorr-1)) & xorr;
  
  int bucket1 = 0;
  int bucket2 = 0;

  for (int i = 0; i < n; i++) {
    if (rightSetBit & nums[i]) bucket1 = bucket1 ^ nums[i];
    else bucket2 = bucket2 ^ nums[i];
  }

  return pair<int, int>{bucket1, bucket2};
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

  pair<int, int> ans = find2NumAppearsOddTimes(nums);
  
  cout << ans.first << " " << ans.second;

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;

}
