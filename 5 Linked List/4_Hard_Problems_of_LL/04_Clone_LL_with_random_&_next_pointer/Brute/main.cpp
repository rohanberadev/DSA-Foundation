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
	map<Node*, Node*> nodeMap;

	Node* node = head;
	while (node != nullptr) {
		nodeMap[node] = new Node(node->data);
		node = node->next;
	}

	node = head;
	while (node != nullptr) {
		nodeMap[node]->next = nodeMap[node->next];
		nodeMap[node]->random = nodeMap[node->random];
		node = node->next;
	}

	return nodeMap[head];
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