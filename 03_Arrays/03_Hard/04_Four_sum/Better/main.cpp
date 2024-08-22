#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> arr, int target) {
  int n = arr.size();

  set<vector<int>> st;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      set<long long> hashset;

      for (int k = j+1; k < n; k++) {
        long long rem = 1ll * target - (1ll * arr[i] + arr[j] + arr[k]);

        if (hashset.find(rem) != hashset.end()) {
          vector<int> res = {arr[i], arr[j], arr[k], int(rem)};
          sort(res.begin(),res.end());
          st.insert(res);
        }
        
        hashset.insert(arr[k]);
      }
    }
  }

  vector<vector<int>> ans;
  
  for (vector<int> it : st) ans.push_back(it);

  return ans;
} 