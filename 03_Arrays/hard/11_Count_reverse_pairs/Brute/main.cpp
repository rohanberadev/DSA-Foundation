#include <bits/stdc++.h>
using namespace std;

int reversePairs(vector<int> arr) {
  int n = arr.size();

  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (arr[i] > 2*arr[j]) cnt++;
    }
  }

  return cnt;
}