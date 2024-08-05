#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class Stack {
  private:
    int* ds;
    int top;
    int s;

  public:
    Stack(int s) {
      ds = new int[1000];
      top = -1;
      s = s;
    }

    void push(int x) {
      ds[++top] = x;
    }

    int pop() {
      if (top == -1) {
        cerr << "Stack is empty!";
        return 1;
      }
      return ds[top--];
    }

    bool empty() {
      return top == -1;
    }

    int size() {
      return top + 1;
    }

    int getTop() {
      return ds[top];
    }

    int getSize() {
      return s;
    }

    void print() {
      for (int i = 0; i <= top; i++) cout << ds[i] << " "; 
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
  
  Stack st(1000);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.push(x);
  }

  while (!st.empty()) {
    cout << st.getTop() << " ";
    st.pop();
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
