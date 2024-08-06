#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class Stack {
  private:
    int* ds;
    int top;
    int maxSize;

  public:
    Stack(int size) {
      top = -1;
      maxSize = size;
      ds = new int[maxSize];
    }

    void push(int x) {
      if (top >= maxSize) {
        cerr << "Size exceeded!";
        exit(1);
      } 
      ds[++top] = x;
    }

    void pop() {
      if (top == -1) {
        cerr << "Stack is empty!";
        exit(1);
      }
      top--;
    }

    bool empty() {
      return top == -1;
    }

    int size() {
      return top + 1;
    }

    int peek() {
      return ds[top];
    }

    int getSize() {
      return top + 1;
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
    cout << st.peek() << " ";
    st.pop();
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
