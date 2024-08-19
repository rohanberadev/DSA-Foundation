#include <bits/stdc++.h>
using namespace std;

int totalFruits(vector<int> arr) {
  int n = arr.size();

  if (n == 1)
    return 1;

  int i = 0, j = 0, maxi = 0;
  int elem1 = arr[0], elem2 = -1;
  int ind1 = 0, ind2 = 0;
  int lastConsec = 0;

  while (j < n) {
    if (elem2 != -1 && elem1 != arr[j] && elem2 != arr[j]) {
      i = lastConsec;

      elem1 = arr[i];
      elem2 = arr[j];
    }

    elem2 = (elem1 != arr[j] && elem2 == -1) ? arr[j] : elem2;

    if (arr[j] != arr[lastConsec])
      lastConsec = j;

    maxi = max(maxi, j - i + 1);
    j++;
  }

  return maxi;
}