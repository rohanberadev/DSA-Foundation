#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int> nums, int goal) {
  int n = nums.size();
  int cnt = 0;

  unordered_map<int, int> mpp;
  int preSum = 0;

  for (int i = 0; i < n; i++) {
    preSum += nums[i];

    if (preSum == goal)
      cnt++;

    int rem = preSum - goal;

    if (mpp.find(rem) != mpp.end())
      cnt += mpp[rem];

    mpp[preSum] += 1;
  }

  return cnt;
}