#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class MinStack {
  private:
    stack<pair<int, int>> st;

  public:
    MinStack() {}

    void push(int val) {
      if (st.empty()) st.push({val, val});
      else st.push({val, min(val, st.top().second)});
    }

    void pop() {
      st.pop();
    }

    int top() {
      if (st.empty()) {
        cerr << "Min Stack is empty.";
        exit(1);
      }
      return st.top().first;
    }

    int getMin() {
      if (st.empty()) {
        cerr << "Min Stack is empty.";
        exit(1);
      }
      return st.top().second;
    }

    bool empty() {
      return st.empty();
    }
};

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
  
  int n;
  cin >> n;
  
  MinStack mst;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    mst.push(val);
  }

  while (!mst.empty()) {
    cout << "Top: " << mst.top() << " Min: " << mst.getMin() << endl;
    mst.pop();
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
