#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void mergeArr(vector<int> &arr, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;

  vector<int> temp;

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
    else temp.push_back(arr[right++]);
  }

  while (left <= mid) temp.push_back(arr[left++]);
  while (right <= high) temp.push_back(arr[right++]);

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i-low];
  }
}

void mergeSort_util(vector<int> &arr, int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;

    mergeSort_util(arr, low, mid);
    mergeSort_util(arr, mid+1, high);
    mergeArr(arr, low, mid, high);
  }
}

void mergeSort(vector<int> &arr) {
  mergeSort_util(arr, 0, arr.size()-1);
}

int main() {
  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input file.";
    return 1;
  } 

  streambuf* cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());

  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output file.";
    return 1;
  }
  
  streambuf* coutbuf = cout.rdbuf();
  cout.rdbuf(outfile.rdbuf());
  
  int size;
  cin >> size;

  vector<int> arr(size);
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  mergeSort(arr);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  } 

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
