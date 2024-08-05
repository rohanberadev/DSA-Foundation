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

Node* findMidNode(Node *head) {
	Node* slow = head;
	Node *fast = head->next;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

Node* merge2List(Node* left, Node* right) {
	Node* dummy = new Node(-1);
	Node* temp = dummy;

	while (left != nullptr && right != nullptr) {
		if (left->data <= right->data) {
			temp->next = left;
			left = left->next;
		} else {
			temp->next = right;
			right = right->next;
		}
		temp = temp->next;
	}

	if (left != nullptr) {
		temp->next = left;
	} else {
		temp->next = right;
	}

	Node* newHead = dummy->next;
	dummy->next = nullptr;
	delete dummy;

	return newHead;
}

Node* mergeSortList(Node* head) {
	if (empty(head) || head->next == nullptr) {
		return head;
	}

	Node* mid = findMidNode(head);
	Node* left = head;
	Node *right = mid->next;
	mid->next = nullptr;

	left = mergeSortList(left);
	right = mergeSortList(right);

	return merge2List(left, right);
}

Node* sortList(Node* head) {
	return mergeSortList(head);
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

	head = sortList(head);
	print_list(head);

	return 0;
}