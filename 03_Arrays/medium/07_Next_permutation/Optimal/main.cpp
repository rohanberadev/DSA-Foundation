#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void reverseArr(vector<int> &arr, int i, int j) {
  while (i < j) swap(arr[i++], arr[j--]);
}

vector<int> nextPermutation(vector<int> arr) {
  int n = arr.size();
  int ind = n-2;

  while (ind >= 0 && arr[ind+1] <= arr[ind]) ind--;

  if (ind < 0) {
    reverseArr(arr, 0, n-1);
    return arr;
  }

  for (int i = n-1; i > ind; i--) {
    if (arr[i] > arr[ind]) {
      swap(arr[i], arr[ind]);
      break;
    }
  }

  reverseArr(arr, ind+1, n-1);

  return arr;
}

int main() {
  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input file.";
    return 1;
  }

  streambuf *cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());

  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output file.";
    return 1;
  }

  streambuf *coutbuf = cout.rdbuf();
  cout.rdbuf(outfile.rdbuf());

  int size;
  cin >> size;

  vector<int> arr(size);
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  vector<int> nextPerm = nextPermutation(arr);
  for (int it : nextPerm)
    cout << it << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
