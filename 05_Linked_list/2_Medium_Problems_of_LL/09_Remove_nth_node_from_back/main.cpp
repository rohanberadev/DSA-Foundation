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

int get_length(Node* head) {
	int len = 0;
	Node* node = head;
	while (node != nullptr) {
		node = node->next;
		len++;
	}

	return len;
}

Node* deleteNthNodeFromBack_brute(Node* head, int n) {
	int len = get_length(head);

	if (len < n) {
		cout << "Size of linked list is not sufficient to delete" << n << " th node." << endl;
		return head;
	}

	if (len == n) {
		Node* newHead = head->next;
		head->next = nullptr;
		delete head;
		return newHead;
	}

	int k = len - n;
	k--;

	Node* node = head;
	while (node != nullptr && k > 0) {
		node = node->next;
		k--;
	}

	Node *delNode = node->next;
	node->next = node->next->next;
	delete delNode;

	return head;
}

Node* deleteNthNodeFromBack_optimal(Node* head, int n) {
	Node* slow = head;
	Node* fast = head;

	while (fast != nullptr && n > 0) {
		fast = fast->next;
		n--;
	}

	if (fast == nullptr) {
		Node* newHead = head->next;
		head->next = nullptr;
		delete head;
		return newHead;
	}

	while (fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next;
	}

	Node* delNode = slow->next;
	slow->next = slow->next->next;
	delNode->next = nullptr;
	delete delNode;

	return head;
}

int main() {

	int size;
	cin >> size;

	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	int n;
	cin >> n;

	Node* head = convertArrayToList(arr, size);
	print_list(head);

	head = deleteNthNodeFromBack_optimal(head, n);
	print_list(head);

	return 0;
}