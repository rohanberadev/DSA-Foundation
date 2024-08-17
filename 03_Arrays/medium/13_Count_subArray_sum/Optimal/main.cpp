#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k) {
  int n = nums.size();
  int cnt = 0;
  unordered_map<int, int> preSumMap;
  int preSum = 0;

  for (int i = 0; i < n; i++) {
    preSum += nums[i];

    if (preSum == k) cnt++;
    
    int rem = preSum - k;

    if (preSumMap.find(rem) != preSumMap.end()) cnt += preSumMap[rem];

    preSumMap[preSum]++;
  }

  return cnt;
}