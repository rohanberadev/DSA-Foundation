#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int findLargestNum(vector<int> &arr) {
  int n = arr.size();
  int maxi = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (arr[i] > maxi)
      maxi = arr[i];
  }

  return maxi;
}

// Link -
// https://bit.ly/3Pld280