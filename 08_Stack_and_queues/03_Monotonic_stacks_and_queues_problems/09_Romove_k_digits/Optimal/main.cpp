#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

string removeKDigits(string num, int k) {
  int n = num.length();

  if (n == k)
    return "0";

  vector<char> st;

  for (int i = 0; i < n; i++) {
    while (k > 0 && !st.empty() && st.back() > num[i]) {
      st.pop_back();
      k--;
    }
    st.push_back(num[i]);
  }

  bool a = true;

  while (k > 0) {
    st.pop_back();
    k--;
  }

  if (st.empty())
    return "0";

  int ind = 0;
  int len = st.size();

  while (ind < len && st[ind] == '0')
    ind++;

  string ans = "";

  for (int i = ind; i < len; i++)
    ans += st[i];

  if (ans == "")
    return "0";

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
