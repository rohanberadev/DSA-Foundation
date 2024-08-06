#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class Stack {
  private:
    queue<int> q;
  
  public:
    Stack() {}

    void push(int x) {
      int s = q.size();
      q.push(x);
      
      // Time :- O(N)
      for (int i = 1; i <= s; i++) {
        q.push(q.front());
        q.pop();
      }
    }

    void pop() {
      q.pop();
    }

    int peek() {
      return q.front();
    }

    int size() {
      return q.size();
    }

    bool empty() {
      return q.empty();
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
  
  Stack st;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.push(x);
  }
  
  while (!st.empty()) {
    cout << st.peek() << " ";
    st.pop();
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
