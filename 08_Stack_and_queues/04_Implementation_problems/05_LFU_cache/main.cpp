#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class LFUCache {
private:
  struct Node {
    int key;
    int value;
    int cnt;

    Node* next;
    Node* prev;

    Node(int key, int value, int cnt = 1, Node* next = nullptr, Node* prev = nullptr) : 
      key(key), value(value), cnt(cnt), next(next), prev(prev) {}
  };

  int capacity;
  map<int, int> store;
  Node* head;
  Node* tail;

  void addNode(Node* element) {
    element->next = head->next;
    head->next = element->next;
    element->prev = head;
    element->next->prev = element;
  }

public:
  LFUCache(int capacity) {
    this->capacity = capacity;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }
    
  int get(int key) {
    return -1;
  }

  void put(int key, int value) {
   
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

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}