#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;

  // constructor
  Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

bool empty(Node *head) { return head == nullptr; }

void print_list(Node *head) {
  if (empty(head)) {
    cout << "List is empty." << endl;
  }

  for (Node *node = head; node != nullptr; node = node->next) {
    cout << node->data << " ";
  }
  cout << endl;
}

Node *convertArrayToList(int arr[], int n) {
  Node *head = new Node(arr[0]);
  Node *node = head;

  for (int i = 1; i < n; i++) {
    node->next = new Node(arr[i]);
    node = node->next;
  }

  return head;
}

Node *getKthNode(Node *head, int k) {
  k--;
  Node *node = head;
  while (node != nullptr && k > 0) {
    node = node->next;
    k--;
  }

  return node;
}

Node *rotateRight(Node *head, int k) {

  if (empty(head) || head->next == nullptr) {
    return head;
  }

  int len = 1;
  Node *tail = head;
  while (tail->next != nullptr) {
    tail = tail->next;
    len++;
  }

  k = k % len;

  if (k == 0) {
    return head;
  }

  k = len - k;

  Node *kthNode = getKthNode(head, k);
  Node *newHead = kthNode->next;

  kthNode->next = nullptr;
  tail->next = head;
  head = newHead;

  return head;
}

int main() {

  int size;
  cin >> size;

  int k;
  cin >> k;

  int arr[size];
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  Node *head = convertArrayToList(arr, size);
  print_list(head);

  head = rotateRight(head, k);
  print_list(head);

  return 0;
}