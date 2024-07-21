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

void printDoublyList(Node* head) {
	for (Node* node = head; node != nullptr; node = node->next) {
		cout << node->data << " ";
	}
	cout << endl;
}

Node* deleteAllOccurences(Node* head, int key) {
	Node* dummy = new Node(-1);
	Node* temp = dummy;

	Node* node = head;
	while (node != nullptr) {
		Node* next = node->next;
		node->next = nullptr;

		if (node->data != key) {
			temp->next = node;
			node->prev = temp;
			temp = temp->next;
		}
		
		node = next;
	}

	return dummy->next;
}

int main() {

	int size;
	cin >> size;

	int key;
	cin >> key;

	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	Node* head = convertArrayToDoublyList(arr, size);
	printDoublyList(head);

	head = deleteAllOccurences(head, key);
	printDoublyList(head);

	return 0;
}