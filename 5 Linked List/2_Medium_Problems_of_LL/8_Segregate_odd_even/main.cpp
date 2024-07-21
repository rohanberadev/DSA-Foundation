#include<bits/stdc++.h>
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

Node* convertArrayToList(int arr[], int n) {
	Node* head = new Node(arr[0]);
	Node* node = head;

	for (int i = 1; i < n; i++) {
		node->next = new Node(arr[i]);
		node = node->next;
	}

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

Node* segregateOddAndEven(Node* head) {
	Node* dummyOdd = new Node(-1);
	Node* dummyEven = new Node(-1);

	Node* tempOdd = dummyOdd;
	Node* tempEven = dummyEven;

	Node* node = head;
	while (node != nullptr) {
		if (node->data % 2 == 0) {
			tempEven->next = node;
			tempEven = tempEven->next;
		} else {
			tempOdd->next = node;
			tempOdd = tempOdd->next;
		}
		node = node->next;
	}

	tempEven->next = dummyOdd->next;
	tempOdd->next = nullptr;

	return dummyEven->next;
}

int main() {

	int size;
	cin >> size;

	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	Node* head = convertArrayToList(arr, size);
	print_list(head);

	head = segregateOddAndEven(head);
	print_list(head);

	return 0;
}