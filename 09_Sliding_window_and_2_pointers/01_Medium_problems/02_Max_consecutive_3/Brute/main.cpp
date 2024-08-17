#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k) {
  int n = nums.size();

  int maxLen = 0;
  int temp = k;

  for (int i = 0; i < n; i++) {
    k = temp;
    for (int j = i; j < n; j++) {
      if (nums[j] == 0 && k <= 0) break;
      if (nums[j] == 0) k--;

      maxLen = max(maxLen, j-i+1);
    }
  }

  return maxLen;
}