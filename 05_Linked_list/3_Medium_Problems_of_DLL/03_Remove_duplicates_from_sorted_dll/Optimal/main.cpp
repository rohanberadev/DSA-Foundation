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

// Time :- O(N) Space :- O(1)
Node* removeDuplicates(Node* head) {
	Node* node = head;

	while (node != nullptr) {
		Node* next = node->next;
		if (node->prev != nullptr) {
			if (node->prev->data == node->data) {
				Node* prev = node->prev;
				prev->next = node->next;
				if (node->next != nullptr) node->next->prev = prev;

				delete node;
			}
		}
		node = next;
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

	Node* head = convertArrayToDoublyList(arr, size);
	printDoublyList(head);

	head = removeDuplicates(head);
	printDoublyList(head);

	return 0;
}