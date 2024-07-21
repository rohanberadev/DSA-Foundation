#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;

	// constructor
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

bool empty(Node* head) {
	return head == nullptr;
}

Node* insert_at_front(Node* head, int data) {
	Node* newNode = new Node(data);
	newNode->next = head;
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

	return head;
}

Node* delete_at_front(Node* head) {
	if (empty(head)) {
		cout << "List is empty." << endl;
		return nullptr;
	}

	Node* newHead = head->next;
	head->next = nullptr;
	delete head;
	return newHead;
}

Node* delete_at_back(Node* head) {
	if (empty(head)) {
		cout << "List is empty." << endl;
		return nullptr;
	}

	if (head->next == nullptr) {
		delete head;
		return nullptr;
	}

	Node* node = head;
	while (node->next->next != nullptr) {
		node = node->next;
	}

	Node* delNode = node->next;
	node->next = node->next->next;
	delNode->next = nullptr;
	delete delNode;

	return head;
}

void print_list(Node* head) {
	if (empty(head)) {
		cout << "List is empty." << endl;
	}

	for (Node* node = head; node != nullptr; node = node->next) {
		cout << node->data << " ";
	}
	cout << endl;
}

int get_length(Node* head) {
	int len = 0;
	for (Node* node = head; node != nullptr; node = node->next) {
		len++;
	}

	return len;
}

bool contains(Node* head, int target) {
	for (Node* node = head; node != nullptr; node = node->next) {
		if (node->data == target) {
			return true; 
		}
	}

	return false;
}

Node* convertArrayToList(int arr[], int n) {
	Node* head = new Node(arr[0]);
	Node* node = head;

	for (int i = 1; i < n; i++) {
		node->next = new Node(arr[i]);
		node = node->next;
	}

	return head;
}

int main() {

	int size;
	cin >> size;

	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	Node* head = new Node(arr[0]);
	for (int i = 1; i < size; i++) {
		head = insert_at_front(head, arr[i]);
	}

	cout << contains(head, 3);

	return 0;
}