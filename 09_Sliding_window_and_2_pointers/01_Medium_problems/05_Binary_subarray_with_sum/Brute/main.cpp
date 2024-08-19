#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int> nums, int goal) {
  int n = nums.size();
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      if (sum > goal)
        break;

      sum += nums[j];
      if (sum == goal)
        cnt++;
    }
  }

  return cnt;
}