#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
#include <vector>
using namespace std;

void mergeArr(vector<int> &arr, int low, int mid, int high) {
  int i = low;
  int j = mid+1;

  vector<int> temp;

  while (i <= mid && j <= high) {
    if (arr[i] <= arr[j]) {
      temp.push_back(arr[i]);
      i++;
    }
    else {
      temp.push_back(arr[j]);
      j++;
    }
  }

  while (i <= mid) temp.push_back(arr[i++]);
  while (j <= high) temp.push_back(arr[j++]);

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i-low];
  }
}

void mergeSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    mergeArr(arr, low, mid, high);
  }
}

// Time :- O(N * Log(N))
// Space :- O(1)
vector<int> sortArray_brute(vector<int> arr) {
  mergeSort(arr, 0, arr.size()-1);
  return arr;
}

// Time :- O(2 * N)
// Space :- O(1)
vector<int> sortArray_better(vector<int> arr) {
  int cnt_0 = 0;
  int cnt_1 = 0;
  int cnt_2 = 0;

  int n = arr.size();

  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) cnt_0++;
    else if (arr[i] == 1) cnt_1++;
    else if (arr[i] == 2) cnt_2++;
  }

  for (int i = 0; i < n; i++) {
    if (cnt_0 > 0) {
      arr[i] = 0;
      cnt_0--;
    }
    else if (cnt_1 > 0) {
      arr[i] = 1;
      cnt_1--;
    }
    else if (cnt_2 > 0) {
      arr[i] = 2;
      cnt_2--;
    }
  }

  return arr;
}

vector<int> sortArr_optimal(vector<int> arr) {
  int n = arr.size();
  
  int i = 0;
  int j = 0;
  int k = n-1;

  while (j <= k) {
    if (arr[j] == 0) swap(arr[i++], arr[j++]);
    else if (arr[j] == 2) swap(arr[j], arr[k--]);
    else if (arr[j] == 1) j++;
  }
  
  return arr;
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
  
  vector<int> brute = sortArray_brute(arr);
  cout << "Brute: ";
  for (auto it : brute) cout << it << " ";
  cout << endl;
  
  cout << "Better: ";
  vector<int> better = sortArray_better(arr);
  for (auto it : better) cout << it << " ";
  cout << endl;

  cout << "Optimal: ";
  vector<int> optimal = sortArr_optimal(arr);
  for (auto it : optimal) cout << it << " ";
  cout << endl;

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
