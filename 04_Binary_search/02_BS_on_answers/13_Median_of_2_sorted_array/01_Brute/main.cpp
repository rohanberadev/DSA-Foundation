#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int n1 = nums1.size();
  int n2 = nums2.size();

  vector<int> temp;
  int i = 0, j = 0;

  while (i < n1 && j < n2) {
    if (nums1[i] <= nums2[j]) {
      temp.push_back(nums1[i]);
      i++;
    }

    else {
      temp.push_back(nums2[j]);
      j++;
    }
  }

  while (i < n1)
    temp.push_back(nums1[i++]);
  while (j < n2)
    temp.push_back(nums2[j++]);

  int n = temp.size();

  if (n % 2 == 0) {
    return double(temp[(n / 2) - 1] + temp[n / 2]) / 2.0;
  }

  return temp[n / 2];
}

// Link -
// https://leetcode.com/problems/median-of-two-sorted-arrays/