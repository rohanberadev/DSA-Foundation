#include <bits/stdc++.h>
#include <climits>
using namespace std;

vector<int> majorityElement(vector<int> arr) {
  int n = arr.size();

  long elem1 = LONG_MIN;
  long elem2 = LONG_MIN;
  int cnt1 = 0;
  int cnt2 = 0;

  vector<int> ans;

  for (int i = 0; i < n; i++) {
    if (cnt1 == 0 && elem2 != arr[i]) {
      cnt1 = 1;
      elem1 = arr[i];
    }

    else if (cnt2 == 0 && elem1 != arr[i]) {
      cnt2 = 1;
      elem2 = arr[i];
    }

    else if (arr[i] == elem1) cnt1++;

    else if (arr[i] == elem2) cnt2++;

    else {
      cnt1--;
      cnt2--;
    }
  }

  cnt1 = 0, cnt2 = 0;

  for (int i = 0; i < n; i++) {
    if (elem1 == arr[i]) cnt1++;
    if (elem2 == arr[i]) cnt2++;
  }

  if (cnt1 > n/3) ans.push_back(elem1);
  if (cnt2 > n/3) ans.push_back(elem2);

  return ans; 
}