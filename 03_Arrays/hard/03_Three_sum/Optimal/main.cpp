#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

vector<vector<int>> threeSum(vector<int> arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());

  vector<vector<int>> ans;

  for (int i = 0; i < n; i++) {
    if (i > 0 && arr[i-1] == arr[i]) continue;
    int l = i+1;
    int r = n-1;

    while (l < r) {
      int sum = arr[i] + arr[l] + arr[r];

      if (sum < 0) l++;

      else if (sum > 0) r--;

      else {
        ans.push_back({arr[i], arr[l], arr[r]});
        l++, r--;

        while (l < r && arr[l-1] == arr[l]) l++;
        while (r > l && arr[r+1] == arr[r]) r--; 
      }
    }
  }

  return ans;
}