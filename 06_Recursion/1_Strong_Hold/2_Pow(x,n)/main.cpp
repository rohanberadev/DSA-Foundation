#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// Time :- O(log N)
double pow_iterative(double x, int n) {
  double ans = 1;
  bool sign = false;

  if (x == 1) {
    return x;
  }

  if (n < 0) {
    sign = true;
  }

  n = abs(n);

  while (n > 0) {
    if (n % 2 == 0) {
      x = x * x;
      n = n / 2;
    }

    else {
      ans = ans * x;
      n = n - 1;
    }
  }

  if (sign) {
    return 1.0 / ans;
  }

  return ans;
}

// Time :- O(log N)
double pow_recursive(double x, int n) {
  double ans = 1;

  if (n == 0) {
    return 1;
  }

  if (n % 2 == 0) {
    x = x * x;
    n = n / 2;
  }

  else {
    ans = ans * x;
    n = n - 1;
  }

  return ans * pow_recursive(x, n);
}

double myPow(double x, int n) {
  if (n < 0) {
    return 1.0 / pow_recursive(x, abs(n));
  }

  else {
    return pow_recursive(x, n);
  }
}

// Link -
// https://leetcode.com/problems/powx-n/