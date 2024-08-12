#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

vector<int> rearrangeArray(vector<int> arr) {
  int n = arr.size();
  vector<int> pos;
  vector<int> neg;
  vector<int> ans(n);

  for (int i = 0; i < n; i++) {
    if (arr[i] < 0)
      neg.push_back(arr[i]);
    else
      pos.push_back(arr[i]);
  }

  if (pos.size() > neg.size()) {
    for (int i = 0; i < neg.size(); i++) {
      ans[2 * i] = pos[i];
      ans[2 * i + 1] = neg[i];
    }

    int ind = neg.size() * 2;
    for (int i = neg.size(); i < pos.size(); i++) {
      ans[ind++] = pos[i];
    }
  } else {
    for (int i = 0; i < pos.size(); i++) {
      ans[2 * i] = pos[i];
      ans[2 * i + 1] = neg[i];
    }

    int ind = pos.size() * 2;
    for (int i = pos.size(); i < neg.size(); i++) {
      ans[ind++] = neg[i];
    }
  }

  return ans;
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

  vector<int> ans = rearrangeArray(arr);
  for (auto it : ans)
    cout << it << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
