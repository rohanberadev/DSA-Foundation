#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

vector<int> findUnion(vector<int> arr1, vector<int> arr2) {
  int n1 = arr1.size();
  int n2 = arr2.size();
  
  int i = 0;
  int j = 0;
  
  vector<int> temp;

  while (i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      if (temp.size() == 0) temp.push_back(arr1[i]);
      else if (temp[temp.size()-1] != arr1[i]) temp.push_back(arr1[i]);
  
      if (arr1[i] == arr2[j]) j++;
      i++;
    }
    else {
      if (temp.size() == 0) temp.push_back(arr2[j]) temp.push_back(arr2[j]);
      else if (temp[temp.size()-1] != arr2[j]) temp.push_back(arr2[j]);
      j++;
    }
  }
  
  while (i < n1) {
    if (temp[temp.size()-1] != arr1[i]) temp.push_back(arr1[i]);
    i++;
  }
  
  while (j < n2) {
    if (temp[temp.size()-1] != arr2[j]) temp.push_back(arr2[j]);
    j++;
  }
  
  return temp;
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
  
  int n1, n2;
  cin >> n1 >> n2;
  
  vector<int> arr1(n1);
  for (int i = 0; i < n1; i++) cin >> arr1[i];

  vector<int> arr2(n2);
  for (int i = 0; i < n2; i++) cin >> arr2[i];

  vector<int> ans = findUnion(arr1, arr2);

  for (auto it : ans) cout << it << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
