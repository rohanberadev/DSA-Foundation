#include <bits/stdc++.h>
using namespace std;

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

void print_list(Node* head) {
	if (empty(head)) {
		cout << "List is empty." << endl;
	}

	for (Node* node = head; node != nullptr; node = node->next) {
		cout << node->data << " ";
	}
	cout << endl;
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

Node* sort0_1_2List(Node* head) {
	Node* dummy0 = new Node(-1);
	Node* temp0 = dummy0;

	Node* dummy1 = new Node(-1);
	Node* temp1 = dummy1;

	Node* dummy2 = new Node(-1);
	Node* temp2 = dummy2;

	Node* node = head;
	while (node != nullptr) {
		Node* next = node->next;
		node->next = nullptr;

		if (node->data == 0) {
			temp0->next = node;
			temp0 = temp0->next;
		}
		else if (node->data == 1) {
			temp1->next = node;
			temp1 = temp1->next;
		} 
		else if (node->data == 2) {
			temp2->next = node;
			temp2 = temp2->next;
		}

		node = next;
	}

	temp0->next = dummy1->next;
	temp1->next = dummy2->next;

	Node* newHead = dummy0->next;

	delete dummy0;
	delete dummy1;
	delete dummy2;

	return newHead;
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

	head = sort0_1_2List(head);
	print_list(head);

	return 0;
}