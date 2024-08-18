#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n) {
  int missing;
  int repeat;

  for (int num = 1; num <= n; num++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (num == arr[i]) cnt++;
    }

    if (cnt == 2) repeat = num;
    else if (cnt == 0) missing = num;
  }

  return {repeat, missing};
}