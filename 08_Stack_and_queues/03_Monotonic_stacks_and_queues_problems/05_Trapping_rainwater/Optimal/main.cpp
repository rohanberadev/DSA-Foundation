#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

// Time :- O(2 * N)
// Space :- O(N)
int trapRainWater(vector<int> &height) {
  int n = height.size();
  vector<int> suffixMax(n);
  int cnt = 0;
  int prefixMax = height[0];
  
  for (int i = n-2; i >= 0; i--) {
    suffixMax[i] = max(suffixMax[i+1],height[i]);
  }
  
  for (int i = 0; i < n; i++) { 
    int rightMax = suffixMax[i];
    int leftMax = prefixMax;

    if (leftMax > height[i] && rightMax > height[i]) cnt += min(leftMax, rightMax) - height[i];
    prefixMax = max(prefixMax, height[i]);
  }
  
  return cnt;
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
  
  int n;
  cin >> n;
  
  vector<int> height(n);
  for (int i = 0; i < n; i++) cin >> height[i];

  cout << trapRainWater(height);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
