#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class LFUCache {
private:
  struct Node {
    pair<int, int> data;

    Node* next;
    Node* prev;
    int freq;

    Node(int key, int value, int freq = 1, Node* next = nullptr, Node* prev = nullptr) : 
      data({key, value}), next(next), prev(prev), freq(freq) {}
  };

  struct List {
    Node* head;
    Node* tail;

    List() {
      Node* head = new Node(-1, -1, -1);
      Node* tail = new Node(-1, -1, -1);
      head->next = tail;
      tail->prev = head;

      this->head = head;
      this->tail = tail;
    }

    bool empty() {
      return head->next == tail;
    }

    void removeNode(Node* node) {
      Node* prevNode = node->prev;
      Node* nextNode = node->next;

      prevNode->next = nextNode;
      nextNode->prev = prevNode;
    }

    void addFront(Node* node) {
      node->next = head->next;
      head->next = node;
      node->prev = head;
      node->next->prev = node;
    }
  };

  int capacity;
  map<int, Node*> store;
  map<int, List*> freqLists;
  int leastFrequency;

  void updateFrequency(Node* node) {
    int freq = node->freq;

    if (freqLists[freq]->empty()) {
      List* delList = freqLists[freq];
      freqLists.erase(freq);
      delete  delList;
    }

    node->freq += 1;

    if (freqLists.find(node->freq) == freqLists.end()) freqLists[node->freq] = new List();

    freqLists[node->freq]->addFront(node);

    if (freqLists.find(leastFrequency) == freqLists.end()) leastFrequency++;
  }

public:
  LFUCache(int capacity) {
    this->capacity = capacity;
    leastFrequency = 0;
  }
    
  int get(int key) {
    if (store.find(key) == store.end()) return -1;

    Node* node = store[key];

    freqLists[node->freq]->removeNode(node);
    updateFrequency(node);

    return node->data.second;
  }

  void put(int key, int value) {
    if (store.find(key) != store.end()) {
      Node* node = store[key];
      
      freqLists[node->freq]->removeNode(node);
      updateFrequency(node);

      node->data = {key, value};
    }

    else if (store.size() == capacity) {
      Node* node = freqLists[leastFrequency]->tail->prev;
    
      freqLists[leastFrequency]->removeNode(node);
      
      if (freqLists.find(leastFrequency) == freqLists.end()) {
        List* delList = freqLists[leastFrequency];
        freqLists.erase(leastFrequency);
        delete delList;
      }

      if (freqLists.find(1) == freqLists.end()) freqLists[1] = new List();

      store.erase(node->data.first);

      node->data = {key, value};
      node->freq = 1;

      freqLists[1]->addFront(node);
      store[key] = node;

      leastFrequency = 1;
    }

    else {
      Node* node = new Node(key, value);

      if (freqLists.find(1) == freqLists.end()) freqLists[1] = new List();

      freqLists[1]->addFront(node);
      store[key] = node;

      leastFrequency = 1;
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