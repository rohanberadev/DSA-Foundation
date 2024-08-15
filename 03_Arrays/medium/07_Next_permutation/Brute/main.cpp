#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void permute(vector<vector<int>> &ans, vector<int> &arr, vector<int> &ds, vector<bool> &freq, int n) {
  if (ds.size() == n) {
    vector<int> res;
    for (auto it : ds)
      res.push_back(it);
    ans.push_back(res);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!freq[i]) {
      ds.push_back(arr[i]);
      freq[i] = true;

      permute(ans, arr, ds, freq, n);

      ds.pop_back();
      freq[i] = false;
    }
  }
}

int array2Int(vector<int> arr) {
  int n = arr.size();
  int num = 0;
  for (int i = 0; i < n; i++) {
    num *= 10;
    num += arr[i];
  }
  return num;
}

vector<int> nextPermutation(vector<int> arr) {
  int n = arr.size();
  
  int num = array2Int(arr);

  sort(arr.begin(), arr.end());
  vector<vector<int>> perm;
  vector<int> ds;
  vector<bool> freq(n, false);
  permute(perm, arr, ds, freq, n);

  for (vector<int> it : perm) cout << array2Int(it) << endl;

  for (vector<int> it : perm) {
    if (num < array2Int(it)) return it;
  }

  return perm[0];
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
