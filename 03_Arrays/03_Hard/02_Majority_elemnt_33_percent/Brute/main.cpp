#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr) {
  int n = arr.size();

  vector<int> ans;

  for (int i = 0; i < n; i++) {
    int cnt = 1;
    int elem = arr[i];
    for (int j = i+1; j < n; j++) {
      if (elem == arr[j]) cnt++;
    }

    if (cnt > n / 3) ans.push_back(elem);
  }

  return ans;
}