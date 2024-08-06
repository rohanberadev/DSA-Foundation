#include <bits/stdc++.h>
#include <fstream>
#include <stack>
#include <streambuf>
using namespace std;

class Queue {
  private:
    stack<int> st1;
    stack<int> st2;

  public:
    Queue() {}
    
    // Time :- O(2 * N)
    void push(int x) {
      if (st1.empty()) {
        while (!st2.empty()) {
          st1.push(st2.top());
          st2.pop();
        } 

        st2.push(x);

        while (!st1.empty()) {
          st2.push(st1.top());
          st1.pop();
        }
      }
      else {
        while (!st1.empty()) {
          st2.push(st1.top());
          st1.pop();
        } 

        st1.push(x);
        
        while (!st2.empty()) {
          st1.push(st2.top());
          st2.pop();
        }
      }
    }

    void pop() {
      if (st1.empty() && st2.empty()) {
        cerr << "Queue is empty. Nothing to delete!";
        exit(1);
      }
      else if (st1.empty()) st2.pop();
      else if (st2.empty()) st1.pop();
    }

    int peek() {
      if (st1.empty() && st2.empty()) {
        cerr << "Queue is empty. Nothing to peek!";
        exit(1);
      }
      else if (st1.empty()) return st2.top();
      else return st1.top();
    }

    bool empty() {
      return st1.empty() && st2.empty();
    }

    int size() {
      if (empty()) return 0;
      else if (st1.empty()) return st2.size();
      else return st1.size();
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

  Queue q;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    q.push(x);
  }

  while (!q.empty()) {
    cout << q.peek() << " ";
    q.pop();
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
