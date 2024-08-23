#include <bits/stdc++.h>
using namespace std;

bool checkNum(char c) { return c >= '0' && c <= '9'; }

int atoitRecusrive(string s, int ind, int n, long num, long sign) {
  if (ind >= n) {
    return num * sign;
  }

  // removing leading zeroes.
  if (s[ind] == ' ' && sign == 0) {
    return atoitRecusrive(s, ind + 1, n, num, sign);
  }

  // taking +ve sign if it is not there.
  if (s[ind] == '+') {
    if (sign == 0) {
      return atoitRecusrive(s, ind + 1, n, num, +1);
    }

    else {
      atoitRecusrive(s, n, n, num, sign);
    }
  }

  // taking -ve sign if it is not there.
  if (s[ind] == '-') {
    if (sign == 0) {
      return atoitRecusrive(s, ind + 1, n, num, -1);
    }

    else {
      atoitRecusrive(s, n, n, num, sign);
    }
  }

  // checking if the character is a number.
  if (!checkNum(s[ind])) {
    return atoitRecusrive(s, n, n, num, sign);
  }

  // character reaches here if it is a number.
  num = (num * 10) + (s[ind] - '0');

  // if there is not sign until here then it is +ve number.
  if (sign == 0) {
    sign = +1;
  }

  // if number crosses the int boundary
  if (num * sign < INT_MIN) {
    return INT_MIN;
  }

  if (num * sign > INT_MAX) {
    return INT_MAX;
  }

  return atoitRecusrive(s, ind + 1, n, num, sign);
}

int myAtoi(string s) { return atoitRecusrive(s, 0, s.size(), 0, 0); }

// Link -
// https://leetcode.com/problems/string-to-integer-atoi/