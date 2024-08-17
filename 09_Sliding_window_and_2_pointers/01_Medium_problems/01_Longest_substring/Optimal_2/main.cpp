#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
  int n = s.length();

  int left = 0, right = 0, maxLen = 0;
  vector<int> mpp(255, -1);

  while (right < n) {
    if (mpp[s[right]] != -1) {
      if (mpp[s[right]] >= left) left = mpp[right] + 1;
    }

    
    int len = right-left+1;
    maxLen = max(maxLen, len);

    mpp[s[right]] = right;
    right++;
    
  }
  
  return maxLen;
}