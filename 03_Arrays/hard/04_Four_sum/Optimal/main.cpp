#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> arr, int target) {
  int n = arr.size();

  sort(arr.begin(), arr.end());

  vector<vector<int>> ans;

  for (int i = 0; i < n; i++) {
    if (i > 0 && arr[i-1] == arr[i]) continue;

    for (int j = i+1; j < n; j++) {
      if (j > i+1 && arr[j-1] == arr[j]) continue;

      int l = j+1;
      int r = n-1;

      while (l < r) {
        long long sum = 1ll * arr[i] + arr[j] + arr[l] + arr[r];

        if (sum < target) l++;

        else if (sum > target) r--;

        else {
          ans.push_back({arr[i], arr[j], arr[l], arr[r]});
          l++, r--;

          while (l < r && arr[l-1] == arr[l]) l++;
          while (r > l && arr[r+1] == arr[r]) r--; 
        }

      }
    }
  }

  return ans;
}