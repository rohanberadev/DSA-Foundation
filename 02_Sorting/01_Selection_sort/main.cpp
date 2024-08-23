#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void selectionSort(vector<int> &arr) {
  int n = arr.size();

  for (int i = 0; i < n; i++) {
    int sel = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[sel] > arr[j])
        sel = j;
    }

    swap(arr[sel], arr[i]);
  }
}

// Link -
// https://www.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort