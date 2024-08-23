#include <bits/stdc++.h>
using namespace std;

int countSplits(vector<int> &nums, long long maxSum, int k, int n) {
  long long sum = 0;
  int splits = 1;

  for (int i = 0; i < n; i++) {
    if (sum + nums[i] <= maxSum) {
      sum += nums[i];
    }

    else {
      sum = nums[i];
      splits++;
    }
  }

  return splits;
}

int splitArray(vector<int> &nums, int k) {
  int n = nums.size();

  long long low = *max_element(nums.begin(), nums.end());
  long long high = accumulate(nums.begin(), nums.end(), 0);

  while (low <= high) {
    long long mid = (low + high) / 2;

    if (countSplits(nums, mid, k, n) <= k) {
      high = mid - 1;
    }

    else {
      low = mid + 1;
    }
  }

  return low;
}

// Link -
// https://leetcode.com/problems/split-array-largest-sum/