#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* random;

	// constructor
	Node(int data, Node* next = nullptr, Node* random = nullptr) :
	data(data), next(next), random(random) {};
};

void printRandomList(Node* head) {
	Node* node = head;
	while (node != nullptr) {
		cout << node->data << " -> " << node->random->data;
		cout << endl << "|" << endl;
		node = node->next;
	}
	cout << "null" << endl;
}

Node* cloneRandomList(Node* head) {
	Node* node = head;
	while (node != nullptr) {
		Node* next = node->next;

		Node* cloneNode = new Node(node->data);
		node->next = cloneNode;
		cloneNode->next = next;

		node = next;
	}

	node = head;
	while (node != nullptr) {
		// clone node.
		Node* cloneNode = node->next;
		cloneNode->random = node->random->next;
		// next node.
		node = node->next->next;
	}

	Node* dummy = new Node(-1);
	Node* temp = dummy;

	node = head;
	while(node != nullptr) {
		Node* cloneNode = node->next;
		temp->next = cloneNode;

		temp = temp->next;
		node = node->next->next;
	}

	Node* cloneHead = dummy->next;
	dummy->next = nullptr;
	delete dummy;

	return cloneHead;
}

int main() {
	Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printRandomList(head);

    cout << endl;

    cout << "Clone Linked List with Random Pointers:" << endl;
    Node* cloneHead = cloneRandomList(head);
    printRandomList(cloneHead);

	return 0;
}