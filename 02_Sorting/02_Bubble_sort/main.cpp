#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void bubbleSort(vector<int> &arr) {
  int n = arr.size();

  for (int i = n - 1; i >= 0; i--) {
    bool isSwap = false;

    for (int j = 1; j <= i; j++) {
      if (arr[j - 1] > arr[j]) {
        swap(arr[j - 1], arr[j]);
        isSwap = true;
      }
    }

    if (!isSwap)
      break;
  }
}

// Link -
// https://bit.ly/3w6yQx8