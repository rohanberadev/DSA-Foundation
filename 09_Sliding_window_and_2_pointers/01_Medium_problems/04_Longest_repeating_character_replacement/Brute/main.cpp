#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
  int n = s.length();

  vector<int> mpp(255, 0);
  int maxLen = 0;

  for (int i = 0; i < n; i++)
    mpp[s[i]] += 1;

  for (int i = 0; i < n; i++) {
    int used = 0;
    int cnt = 0;
    int end = -1;

    for (int j = i; j < n; j++) {
      if (s[i] != s[j] && (used == mpp[s[i]] || cnt == k)) {
        end = j - 1;
        break;
      }

      if (s[j] != s[i]) {
        used++;
        cnt++;
      }

      maxLen = max(maxLen, j - i + 1);
    }

    if (cnt < k && i > 0 && used < mpp[s[i]]) {
      if (k - cnt <= mpp[s[i]] - used) {
        maxLen = max(maxLen, end - i + 1 + mpp[s[i]]);
      }
    }
  }

  return maxLen;
}