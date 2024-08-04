#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int findPartionIndex(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int left = low;
  int right = high;

  while (left < right) {
    while (left < high && arr[left] <= pivot) left++;

    while (right > low && arr[right] >= pivot) right--;

    if (left < right) swap(arr[left], arr[right]);
  }

  swap(arr[right], arr[low]);

  return right; 
}

void quickSort_util(vector<int> &arr, int low, int high) {
  if (low < high) {
    int partition = findPartionIndex(arr, low,  high);

    quickSort_util(arr, low, partition-1);
    quickSort_util(arr, partition+1, high);
  } 
} 

void quickSort(vector<int> &arr) {
  quickSort_util(arr, 0, arr.size()-1);
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
  
  quickSort(arr);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
