#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;

	// constructor
	Node(int data, Node* next = nullptr, Node* prev = nullptr) : 
	data(data), next(next), prev(prev) {}
};

bool empty(Node* head) {
	return head == nullptr;
}

Node* insert_at_front(Node* head, int data) {
	Node* newNode = new Node(data);
	newNode->next = head;

	if (newNode->next != nullptr) {
		head->prev = newNode;
	}

	return newNode;
}

Node* insert_at_back(Node* head, int data) {
	Node* newNode = new Node(data);
	if (empty(head)) {
		return newNode;
	}

	Node* node = head;
	while (node->next != nullptr) {
		node = node->next;
	}

	node->next = newNode;
	newNode->prev = newNode;

	return head;
}

Node* delete_at_front(Node* head) {
	if (empty(head)) {
		cout << "List is empty" << endl;
		return nullptr;
	}

	Node* newHead = head->next;

	if (newHead != nullptr) {
		newHead->prev = nullptr;
	}
	head->next = nullptr;

	delete head;
	return newHead;
}

Node* delete_at_back(Node* head) {
	if (empty(head)) {
		cout << "List is empty" << endl;
		return nullptr;
	}

	if (head->next == nullptr) {
		delete head;
		return nullptr;
	}

	Node *node = head;
	while (node->next->next != nullptr) {
		node = node->next;
	}

	Node* delNode = node->next;
	node->next = node->next->next;
	delNode->prev = nullptr;
	node->next->prev = node;
	delete delNode;

	return head;
}

Node* convertArrayToDoublyList(int arr[], int n) {
	Node* head = new Node(arr[0]);
	Node* temp = head;

	for(int i = 1; i < n; i++) {
		Node* node = new Node(arr[i]);
		temp->next = node;
		node->prev = temp;
		temp = temp->next;
	}

	return head;
}

Node* reverseDoublyList(Node* head) {
	if (empty(head) || head->next == nullptr) {
		return head;
	}

	Node* node = head;
	Node* prev = nullptr;

	while (node != nullptr) {
		Node* next = node->next;
		node->next = prev;
		node->prev = next;

		prev = node;
		node = next;
	}

	return prev;
}

void printDoublyList(Node* head) {
	for (Node* node = head; node != nullptr; node = node->next) {
		cout << node->data << " ";
	}
	cout << endl;
}

int main() {

	int size;
	cin >> size;

	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	Node* head = convertArrayToDoublyList(arr, size);

	printDoublyList(head);

	head = reverseDoublyList(head);

	printDoublyList(head);

	return 0;
}