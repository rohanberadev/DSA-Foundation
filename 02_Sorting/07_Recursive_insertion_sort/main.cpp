#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void insertionSort_util(vector<int> &arr, int i) {
  if (i == arr.size())
    return;

  int j = i - 1;
  while (j >= 0 && arr[j] > arr[j + 1]) {
    swap(arr[j], arr[j + 1]);
    j--;
  }

  insertionSort_util(arr, i + 1);
}

void insertionSort(vector<int> &arr) { insertionSort_util(arr, 1); }

// Link -
// https://bit.ly/3PxAWx1