#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int n1 = nums1.size();
  int n2 = nums2.size();

  int n = n1 + n2;

  int med1 = -1;
  int med2 = -1;

  int cnt = 0;

  int i = 0, j = 0;

  while (i < n1 && j < n2 && cnt != (n / 2) + 1) {
    if (nums1[i] <= nums2[j]) {
      cnt++;

      med1 = med2;
      med2 = nums1[i];

      i++;
    }

    else {
      cnt++;

      med1 = med2;
      med2 = nums2[j];

      j++;
    }
  }

  while (i < n1 && cnt != (n / 2) + 1) {
    cnt++;
    med1 = med2;
    med2 = nums1[i];
    i++;
  }

  while (j < n2 && cnt != (n / 2) + 1) {
    cnt++;
    med1 = med2;
    med2 = nums2[j];
    j++;
  }

  if (n % 2 == 0) {
    return double(med1 + med2) / 2.0;
  }

  return med2;
}

// Link -
// https://leetcode.com/problems/median-of-two-sorted-arrays/