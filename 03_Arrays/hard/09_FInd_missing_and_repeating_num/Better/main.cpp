#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n) {
  unordered_map<int, int> mpp;
  int repeat, missing;

  for (int i = 0; i < n; i++) {
    if (mpp.find(arr[i]) == mpp.end()) mpp[arr[i]] = 1;
    else mpp[arr[i]] += 1;; 
  }

  for (int num = 1; num <= n; num++) {
    if (mpp.find(num) != mpp.end()) {
      if (mpp[num] > 1) repeat = num;
    }
    else missing = num;
  }

  return {repeat, missing};
}