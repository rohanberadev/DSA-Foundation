#include <bits/stdc++.h>
using namespace std;

long long countInversions(vector<long long> arr) {
  int n = arr.size();
  long long int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (arr[i] > arr[j]) cnt++;
    }
  }

  return cnt;
}