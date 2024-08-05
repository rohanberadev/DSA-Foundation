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

Node* findFisrtMiddleNode(Node* head) {
	Node* fMid = nullptr;
	Node* slow = head;
	Node* fast = head;

	while (fast != nullptr && fast->next != nullptr) {
		fMid = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	return fMid;
}

Node* deleteMiddleNode(Node* head) {
	if (empty(head)) {
		return head;
	}

	if (head->next == nullptr) {
		delete head;
		return nullptr;
	}

	Node* midNodeF = findFisrtMiddleNode(head);
	Node* delNode = midNodeF->next;

	midNodeF->next = midNodeF->next->next;
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

	Node* head = convertArrayToList(arr, size);
	print_list(head);

	head = deleteMiddleNode(head);
	print_list(head);

	return 0;
}