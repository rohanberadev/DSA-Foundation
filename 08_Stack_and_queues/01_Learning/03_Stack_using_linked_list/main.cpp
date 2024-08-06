#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

struct Node {
  int data;
  Node* next;

  // constructor
  Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

class Stack {
  private:
    Node* top;
    int currSize;

  public:
    Stack() {
      top = nullptr;
      currSize = 0;
    }

    bool empty() {
      return top == nullptr;
    }

    void push(int x) {
      Node* node = new Node(x);
      node->next = top;
      top = node;
      currSize++;
    }

    void pop() {
      if (top == nullptr) {
        cerr << "Stack is empty. Nothing to delete!";
        exit(1);
      }
      Node* delNode = top;
      top = top->next;
      delete delNode;
      currSize--;
    }

    int size() {
      return currSize;
    }

    int peek() {
      if (empty()) {
        cerr << "Stack is empty. Nothing to peek!";
        exit(1);
      }
      return top->data;
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
