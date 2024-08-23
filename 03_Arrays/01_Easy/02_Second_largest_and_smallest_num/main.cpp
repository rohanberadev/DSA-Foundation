#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int findSecondLargestNum(vector<int> &arr) {
  int n = arr.size();
  int first = INT_MIN;
  int second = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (first < arr[i]) {
      second = first;
      first = arr[i];
    } else if (second < arr[i] && first != arr[i]) {
      second = arr[i];
    }
  }

  return second;
}

int findSecondSmallestNum(vector<int> &arr) {
  int n = arr.size();
  int first = INT_MAX;
  int second = INT_MAX;

  for (int i = 0; i < n; i++) {
    if (first > arr[i]) {
      second = first;
      first = arr[i];
    } else if (second > arr[i] && first != arr[i]) {
      second = arr[i];
    }
  }

  return second;
}

// Link -
// https://bit.ly/3pFvBcN