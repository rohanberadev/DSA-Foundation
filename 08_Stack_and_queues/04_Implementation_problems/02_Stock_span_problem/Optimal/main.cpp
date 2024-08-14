#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class StockSpanner {
private:
  stack<pair<int, int>> st;
  int ind;

public:
  StockSpanner() {
    ind = 0;
  }

  int next(int price) {
    int days = 1;

    while (!st.empty() && st.top().first <= price) st.pop();

    if (st.empty()) days = ind + 1;
    else days = ind - st.top().second;

    st.push({price, ind});
    ind++;

    return days;
  }

};

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

  int n;
  cin >> n;

  vector<string> inputs(n);
  for (int i = 0; i < n; i++) cin >> inputs[i];

  vector<int> query(n);
  for (int i = 0; i < n; i++) cin >> query[i];

  StockSpanner ss;
  cout << "null ";

  for (int i = 1; i < n; i++) {
    if (inputs[i] == "next") cout << ss.next(query[i]) << " ";
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}