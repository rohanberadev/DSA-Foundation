#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class Queue {
  private:
    struct Node {
      int data;
      Node* next;

      // constructor
      Node(int data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* start;
    Node* end;
    int currSize;

  public:
    Queue() {
      start = nullptr;
      end = nullptr;
      currSize = 0;
    }

    bool empty() {
      return start == nullptr && end == nullptr;
    }

    void push(int x) {
      if (empty()) {
        start = new Node(x);
        end = start;
      }
      else {
        end->next = new Node(x);
        end = end->next;
      }
      currSize++;
    }

    void pop() {
      if (empty()) {
        cerr << "Queue is empty. Nothing to delete!";
        exit(1);
      }

      if (start == end) {
        Node* delNode = start;
        delete delNode;
        start = nullptr;
        end = nullptr;
      }
      else {
        Node* delNode = start;
        start = start->next;
        delete delNode;
      }
      currSize--;
    }

    int size() {
      return currSize;
    }

    int peek() {
      if (empty()) {
        cerr << "Queue is empty. Nothing to peek!";
        exit(1);
      }
      return start->data;
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
