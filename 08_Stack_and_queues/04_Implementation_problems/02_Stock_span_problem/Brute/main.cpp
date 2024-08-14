#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class StockSpanner {
private:
  vector<int> prices;
  
public:
  StockSpanner() {

  }

  int next(int price) {
    int n = prices.size();
    int days = 1;

    for (int i = n-1; i >= 0; i--) {
      if (prices[i] > price) break;
      days++;
    }
    prices.push_back(price);
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