#include <bits/stdc++.h>
using namespace std;

// Time :- O(N ^ 2)
// Space :- O(N)
int lengthOfLongestSubstring(string s) {
  int n = s.length();

  int maxLen = 0;

  for (int i = 0; i < n; i++) {
    unordered_set<char> st;
    for (int j = i; j < n; j++) {

      if (st.find(s[j]) != st.end()) {
        maxLen = max(maxLen, j-i);
        st.clear();
        break;
      }

      st.insert(s[j]);
    }

    if (!st.empty()) maxLen = max(maxLen, n-i);
  }

  return maxLen;
}