#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> arr) {
  int n = arr.size();

  sort(arr.begin(), arr.end());

  vector<vector<int>> ans;

  for (int i = 0; i < n; i++) {
    int start = arr[i][0];
    int end = arr[i][1];

    if (!ans.empty() && ans.back()[1] >= end) continue; 

    for (int j = i+1; j < n; j++) {
      if (end >= arr[j][0]) {
        end = max(end, arr[j][1]);
        start = min(start, arr[j][0]);
      }
      else break;
    }

    ans.push_back({start, end});
  }

  return ans;
}