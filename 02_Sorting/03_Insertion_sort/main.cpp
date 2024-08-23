#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void insertionSort(vector<int> &arr) {
  int n = arr.size();

  for (int i = 1; i < n; i++) {
    int j = i - 1;
    while (j >= 0 && arr[j] > arr[j + 1]) {
      swap(arr[j + 1], arr[j]);
      j--;
    }
  }
}

// Link -
// https://bit.ly/3JVcqot