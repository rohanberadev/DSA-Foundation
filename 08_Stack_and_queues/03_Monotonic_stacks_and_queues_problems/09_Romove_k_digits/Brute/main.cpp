#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

void genSubsquence(string &num, vector<string> &sub, string &ds, int ind, int n, int k) {
  if (ds.length() == n-k) {
    sub.push_back(ds);
    return;
  }

  if (ind >= n) return;

  ds.push_back(num[ind]);
  genSubsquence(num, sub, ds, ind+1, n, k);

  ds.pop_back();
  genSubsquence(num, sub, ds, ind+1, n, k);
}

string removeKDigits(string num, int k) {
  int n = num.length();
  string ds = "";
  vector<string> sub;
  genSubsquence(num, sub, ds, 0, n, k);
  
  string mini;

  for (auto it : sub) {
    if (mini.length() == 0 || stoi(mini) > stoi(it)) mini = it;
  }

  string ans = "";
  int ind = 0;
  int len = mini.length();

  while (ind < len && mini[ind] == '0') ind++;

  for (int i = ind; i < len; i++) ans += mini[i];
  
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

  string num;
  int k;

  cin >> num >> k;

  cout << removeKDigits(num, k);

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
