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

Node* findMidNode(Node* head) {
	Node* slow = head;
	Node* fast = head;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

Node* reverseList(Node* head) {
	Node* node = head;
	Node* prev = nullptr;

	while(node != nullptr) {
		Node* next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}

	return prev;
}

bool checkPalindrome(Node* head) {
	if (empty(head) || head->next == nullptr) {
		return true;
	}

	Node* midNode = findMidNode(head);
	Node* n1 = head;
	Node* n2 = reverseList(midNode->next);
	midNode->next = nullptr;

	while(n1 != nullptr && n2 != nullptr) {
		if (n1->data != n2->data) return false;
		n1 = n1->next;
		n2 = n2->next; 
	}

	return true;
}

int main() {

	int size;
	cin >> size;

	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	Node* head = convertArrayToList(arr, size);

	bool isPalindrome = checkPalindrome(head);

	if (isPalindrome) cout << "List is palindrome." << endl;
	else cout << "List is not palindrome." << endl;

	return 0;
}