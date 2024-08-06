#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class MinStack {
  private:
    stack<int> st;
    int mini;   

  public:
    MinStack() {mini = INT_MAX;}

    void push(int val) {
      if (st.empty()) {
        mini = val;
        st.push(val);
      }
      else if (val < mini) {
        st.push(2 * val - mini);
        mini = val;
      }
      else st.push(val);
    }

    void pop() {
      if (st.empty()) exit(1);

      if (st.top() < mini) mini = 2 * mini - st.top();
      st.pop(); 
    }

    int top() {
      if (st.top() < mini) return mini;
      else return st.top();
    }

    int getMin() {
      return mini;
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
