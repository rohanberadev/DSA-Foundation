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

Node* findInstersection(Node* head1, Node* head2) {
	Node* node1 = head1;
	Node* node2 = head2;

	while (node1 != node2) {
		if (node1 == nullptr) node1 = head2;
		if (node2 == nullptr) node2 = head1;
		node1 = node1->next;
		node2 = node2->next;
	}

	return node1;
}

int main() {

	Node* head1 = nullptr;
    head1 = insert_at_back(head1, 1);
    head1 = insert_at_back(head1, 2);
    head1 = insert_at_back(head1, 3);
    head1 = insert_at_back(head1, 4);
    head1 = insert_at_back(head1, 5);
    head1 = insert_at_back(head1, 6);

    Node* head2 = nullptr;
    head2 = insert_at_back(head2, 1); 
    head2->next = head1->next->next;

    print_list(head1);
    print_list(head2);

    Node* intersection = findInstersection(head1, head2);

    if (intersection != nullptr) cout << "Intersection: " << intersection->data << endl;
    else cout << "Intersection not found!" << endl;

    return 0;

 }