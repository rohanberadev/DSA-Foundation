#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k) {
  int n = nums.size();

  int i = 0, j = 0, cntZeroes = 0, maxLen = 0;

  while (j < n) {
    if (cntZeroes == k && nums[j] == 0) {
      while (i <= j && cntZeroes == k) {
        if (nums[i] == 0) cntZeroes--; 
        i++;
      }
    }

    if (nums[j] == 0) cntZeroes++;

    int len = j-i+1;
    maxLen  = max(maxLen, len);

    j++;
  }

  return maxLen;
}