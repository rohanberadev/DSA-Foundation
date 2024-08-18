#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> arr, int n, int target) {
  int cnt = 0;

  int preXorr = 0;
  unordered_map<int, int> preXorrMap;
  preXorrMap[0] = 1;

  for (int i = 0; i < n; i++) {
    preXorr = preXorr ^ arr[i];

    if (preXorr == target) cnt++;

    int rem = preXorr ^ target;

    if (preXorrMap.find(rem) != preXorrMap.end()) cnt += preXorrMap[rem];

    if (preXorrMap.find(preXorr) == preXorrMap.end()) preXorrMap[preXorr] = 1;
    else preXorrMap[preXorr] += 1;
  }
  
  return cnt;
}