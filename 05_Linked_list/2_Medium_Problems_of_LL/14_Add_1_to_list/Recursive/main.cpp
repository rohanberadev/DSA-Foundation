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

int add1ToList_util(Node *head, int num) {
	if (empty(head)) {
		return 0;
	}

	if (head->next == nullptr) {
		int sum = head->data + num;
		head->data = sum % 10;
		return sum / 10;
	}
		
	int carry = add1ToList_util(head->next, num);

	int sum = head->data + carry;
	head->data = sum % 10;

	return sum / 10;
}

Node* add1ToList(Node* head) {
	int carry = add1ToList_util(head, 1);
	if (carry > 0) {
		Node* newHead = new Node(carry);
		newHead->next = head;
		return newHead;
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

	Node* head = convertArrayToList(arr, size);
	print_list(head);

	head = add1ToList(head);
	print_list(head);

	return 0;

}