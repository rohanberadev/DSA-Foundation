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

Node* insert_at_back(Node* head, int data) {
	Node* newNode = new Node(data);

	if (empty(head)) {
		return newNode;
	}

	Node *node = head;
	while (node->next != nullptr) {
		node = node->next;
	}

	node->next = newNode;

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

Node* convertArrayToList(int arr[], int n) {
	Node* head = new Node(arr[0]);
	Node* node = head;

	for (int i = 1; i < n; i++) {
		node->next = new Node(arr[i]);
		node = node->next;
	}

	return head;
}

Node* add2List(Node* head1, Node* head2) {
	Node* node1 = head1;
	Node* node2 = head2;

	Node* dummy = new Node(-1);
	Node* temp = dummy;

	int carry = 0;

	while (node1 != nullptr || node2 != nullptr || carry > 0) {
		int sum = carry;
		if (node1 != nullptr) {
			sum += node1->data;
			node1 = node1->next;
		}

		if (node2 != nullptr) {
			sum += node2->data;
			node2 = node2->next;
		}

		temp->next = new Node(sum % 10);
		carry = sum / 10;
		temp = temp->next;
	}	

	Node* newHead = dummy->next;
	delete dummy;

	return newHead;
}

int main() {

	int size1;
	int size2;
	cin >> size1;
	cin >> size2;

	int arr1[size1];
	for (int i = 0; i < size1; i++) {
		cin >> arr1[i];
	}

	int arr2[size2];
	for (int i = 0; i < size2; i++) {
		cin >> arr2[i];
	}

	Node* head1 = convertArrayToList(arr1, size1);
	print_list(head1);

	Node* head2 = convertArrayToList(arr2, size2);
	print_list(head2);

	Node* head = add2List(head1, head2);
	print_list(head);

	return 0;

}