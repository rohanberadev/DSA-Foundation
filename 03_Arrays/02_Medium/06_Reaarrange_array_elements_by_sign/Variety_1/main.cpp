#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

vector<int> rearrangeArray_brute(vector<int> arr) {
  int n = arr.size();
  vector<int> pos;
  vector<int> neg;

  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) neg.push_back(arr[i]);
    else pos.push_back(arr[i]);
  }

  for (int i = 0; i < n/2; i++) {
    arr[2*i] = pos[i];
    arr[2*i+1] = neg[i];
  }

  return arr;
}

vector<int> rearrangeArray_optimal(vector<int> arr) {
  int n = arr.size();
  vector<int> ans(n, 0);
  int pos = 0;
  int neg = 1;

  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0) {
      ans[pos] = arr[i];
      pos += 2;
    }
    else {
      ans[neg] = arr[i];
      neg += 2;
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
  
  cout << "Brute: ";
  vector<int> brute = rearrangeArray_brute(arr);
  for (int i = 0; i < size; i++) cout << brute[i] << " ";

  cout << endl << "Optimal: ";
  vector<int> optimal = rearrangeArray_optimal(arr);
  for (int i = 0; i < size; i++) cout << optimal[i] << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
