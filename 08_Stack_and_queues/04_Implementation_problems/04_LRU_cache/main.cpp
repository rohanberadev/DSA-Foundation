#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class LRUCache {
private:
  struct Node {
    pair<int, int> data;
    Node* next;
    Node* prev;

    // constructor
    Node(int key, int value, Node* next = nullptr, Node* prev = nullptr) : data({key, value}), next(next), prev(prev) {}
  };

  int capacity;
  map<int, Node*> store;
  Node* head;
  Node* tail;

  void removeNode(Node* element) {
    element->prev->next = element->next; 
    element->next->prev = element->prev;

    element->next = head->next;
    head->next = element;
    element->prev = head;
    element->next->prev = element;
  }

  void addNode(Node* element) {
    element->next = head->next;
    head->next = element;
    element->prev = head;
    element->next->prev = element;
  }

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  } 

  int get(int key) {
    if (store.find(key) == store.end()) return -1;

    Node* element = store[key];

    element->prev->next = element->next; 
    element->next->prev = element->prev;

    element->next = head->next;
    head->next = element;
    element->prev = head;
    element->next->prev = element;
    
    return element->data.second;
  }

  void put(int key, int value) {
    if (store.find(key) != store.end()) {
      Node* element = store[key];
      element->data = {key, value};

      removeNode(element);
    }

    else if (store.size() == capacity) {
      Node* element = tail->prev;
      removeNode(element);

      store.erase(element->data.first);
      element->data = {key, value};
      store[key] = element;
    }

    else {
      Node* element = new Node(key, value);
      addNode(element);

      store[key] = element;
    }
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