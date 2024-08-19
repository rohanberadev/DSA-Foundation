#include <bits/stdc++.h>
using namespace std;

// Time :- O(N ^ 2)
// Space :- O(1)
int totalFruits(vector<int> arr) {
  int n = arr.size();

  if (n == 1)
    return 1;

  int maxi = 0;

  for (int i = 0; i < n; i++) {
    int elem1 = arr[i], elem2 = -1;

    for (int j = i + 1; j < n; j++) {
      if (elem2 != -1 && elem1 != arr[j] && elem2 != arr[j])
        break;

      elem2 = (elem1 != arr[j] && elem2 == -1) ? arr[j] : elem2;

      maxi = max(maxi, j - i + 1);
    }
  }

  return maxi;
}