#include <bits/stdc++.h>
using namespace std;

int power(int mid, int m, int n) {
  long long int ans = 1;

  for (int i = 1; i <= n; i++) {
    ans = ans * (1ll * mid);

    if (ans > m) {
      return 2;
    }
  }

  if (ans == m) {
    return 1;
  }

  return 0;
}

int NthRoot(int n, int m) {
  int low = 1, high = m;
  int ans = -1;

  while (low <= high) {
    int mid = (low + high) / 2;
    int midN = power(mid, m, n);

    if (midN == 1) {
      return mid;
    }

    else if (midN == 0) {
      low = mid + 1;
    }

    else {
      high = mid - 1;
    }
  }

  return ans;
}

// Link -
// https://bit.ly/3zWNyrL