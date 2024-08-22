#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> arr) {
  int n = arr.size();

  sort(arr.begin(), arr.end());

  vector<vector<int>> ans;
  ans.push_back({arr[0][0], arr[0][1]});

  for (int i = 0; i < n; i++) {
    if (ans.back()[1] >= arr[i][0]) {
      ans.back()[1] = max(arr[i][1], ans.back()[1]);
      ans.back()[0] = min(arr[i][0], ans.back()[0]);
    }
    else {
      ans.push_back({arr[i][0], arr[i][1]});
    }
  }

  return ans;
}