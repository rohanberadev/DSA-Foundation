#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr) {
  int n = arr.size();

  unordered_map<int, int> mpp;
  vector<int> ans;

  for (int i = 0; i < n; i++) {
    if (mpp.find(arr[i]) != mpp.end()) {
      mpp[arr[i]] += 1; 
    }
    else {
      mpp[arr[i]] = 1;
    }
  }

  for (pair<int, int> it : mpp) {
    if (it.second > n/3) ans.push_back(it.first);
  }

  return ans;
}