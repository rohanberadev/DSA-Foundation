#include <bits/stdc++.h>
using namespace std;

int func(vector<int> nums, int goal) {
  int n = nums.size();

  if (goal < 0)
    return 0;

  int i = 0, j = 0, cnt = 0;
  int sum = nums[0];

  while (j < n) {
    while (i <= j && sum > goal) {
      sum -= nums[i];
      i++;
    }

    cnt += j - i + 1;

    j++;
    if (j < n) {
      sum += nums[j];
    }
  }

  return cnt;
}

int numSubarraysWithSum(vector<int> nums, int goal) {

  int cnt = func(nums, goal) - func(nums, goal - 1);

  return cnt;
}