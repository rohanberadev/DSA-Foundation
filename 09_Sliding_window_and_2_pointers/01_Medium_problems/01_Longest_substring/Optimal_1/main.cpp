#include <bits/stdc++.h>

using namespace std;

// Time :- O(N)
// Space :- O(N)
int lengthOfLongestSubstring(string s) {
  int n = s.length();
  int l = 0;
  int r = 0;
  int maxLen = 0;

  unordered_set<char> st;

  while (r < n) {
    if (st.find(s[r]) != st.end()) {
      while (!st.empty() && st.find(s[r]) != st.end()) {
        st.erase(s[l]);
        l++;
      }
    }
    maxLen = max(maxLen, r-l+1);
    st.insert(s[r]);
    r++;
  }

  return maxLen;
}