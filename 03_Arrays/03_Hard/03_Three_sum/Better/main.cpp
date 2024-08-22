#include <bits/stdc++.h>
using namespace std;

// Time :- O((N ^ 2) * log(no. of unique triplets))
// Space :- (2 * (no. of unique triplets) + N)
vector<vector<int>> threeSum(vector<int> arr) {
  int n = arr.size();

  set<vector<int>> st;

  for (int i = 0; i < n; i++) {
    set<int> hashset;

    for (int j = i+1; j < n; j++) {
      int rem = 0 - (arr[i] + arr[j]);

      if (hashset.find(rem) != hashset.end()) {
        vector<int> res = {rem, arr[i], arr[j]};
        sort(res.begin(), res.end());
        st.insert(res);
      }
      hashset.insert(arr[j]);
    }
  }

  vector<vector<int>> ans;

  for (auto it : st) {
    ans.push_back(it);
  }

  return ans;
}