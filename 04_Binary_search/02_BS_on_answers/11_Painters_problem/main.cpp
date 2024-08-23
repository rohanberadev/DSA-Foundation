#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int> &boards, long long maxDist, int n) {
  long long paints = 0;
  int painters = 1;

  for (int i = 0; i < n; i++) {
    if (paints + boards[i] <= maxDist) {
      paints += boards[i];
    }

    else {
      paints = boards[i];
      painters++;
    }
  }

  return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {
  int n = boards.size();

  long long low = *max_element(boards.begin(), boards.end());
  long long high = accumulate(boards.begin(), boards.end(), 0);

  while (low <= high) {
    long long mid = (low + high) / 2;

    if (countPainters(boards, mid, n) <= k) {
      high = mid - 1;
    }

    else {
      low = mid + 1;
    }
  }

  return low;
}

// Link -
// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM