#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int> nums, int k) {
  int n = nums.size();
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    int temp = 0;

    for (int j = i; j < n; j++) {
      if (temp > k)
        break;

      if (nums[j] % 2 != 0)
        temp++;

      if (temp == k)
        cnt++;
    }
  }

  return cnt;
}