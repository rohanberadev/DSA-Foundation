#include <bits/stdc++.h>
using namespace std;

int isPossible(vector<int> &nums, long long div, int threshold) {
  int n = nums.size();

  long long res = 0;

  for (int i = 0; i < n; i++) {
    if (res > threshold) {
      return false;
    }

    res += 1ll * ceil(double(nums[i]) / double(div));
  }

  if (res <= threshold) {
    return true;
  }

  return false;
}

long long summation(vector<int> &nums, int n) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
  }

  return sum;
}

int smallestDivisor(vector<int> &nums, int threshold) {
  int n = nums.size();

  long long low = 1, high = summation(nums, n);

  while (low <= high) {
    long long mid = (low + high) / 2;

    if (isPossible(nums, mid, threshold)) {
      high = mid - 1;
    }

    else {
      low = mid + 1;
    }
  }

  return low;
}

// Link -
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/