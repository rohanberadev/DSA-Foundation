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

Node* getKthNode(Node* head, int k) {
	k--;
	Node* node = head;
	while (node != nullptr && k > 0) {
		node = node->next;
		k--;
	}

	return node;
}

Node* reverseList(Node* head) {
	Node* node = head;
	Node* prev = nullptr;

	while (node != nullptr) {
		Node* next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}

	return prev;
}

Node* reverseListInGroups(Node* head, int k) {
	Node* dummy = new Node(-1);
	Node* temp = dummy;
	Node* node = head;

	while (node != nullptr) {
		Node* kthNode = getKthNode(node, k);
		if (kthNode == nullptr) {
			temp->next = node;
			break;
		}

		Node* next = kthNode->next;
		kthNode->next = nullptr;

		reverseList(node);

		temp->next = kthNode;
		temp = node;

		node = next;
	}

	Node* newHead = dummy->next;
	dummy->next = nullptr;
	delete dummy;

	return newHead;
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

	Node* head = convertArrayToList(arr, size);
	print_list(head);


	head = reverseListInGroups(head, k);
	print_list(head);

	return 0;
}