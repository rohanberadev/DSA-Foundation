#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> arr, int target) {
  int n = arr.size();

  set<vector<int>> st;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        for (int l = k+1; l < n; l++) {
          long long sum = 1ll * arr[i] + arr[j] + arr[k] + arr[l];

          if (sum == target) {
            vector<int> res = {arr[i], arr[j], arr[k], arr[l]};
            sort(res.begin(), res.end());
            st.insert(res);
          }

        }
      }
    }
  }

  vector<vector<int>> ans;

  for (vector<int> it : st) {
    ans.push_back(it);
  }

  return ans;
}
