#include <bits/stdc++.h>
using namespace std;

// Time :- O((N ^ 3 )* log(no. of unique triplets))
// Space :- O(1)
vector<vector<int>> threeSum(vector<int> arr) {
  int n = arr.size();

  set<vector<int>> st;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        int sum = arr[i] + arr[j] + arr[k];
        if (sum == 0) {
          vector<int> res = {arr[i], arr[j], arr[k]};
          sort(res.begin(), res.end());
          st.insert(res);
        }
      }
    }
  }

  vector<vector<int>> ans;

  for (vector<int> it: st) {
    ans.push_back(it);
  }

  return ans;
}