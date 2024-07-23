#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* child;

	// constructor
	Node(int data, Node* next = nullptr, Node* child = nullptr) :
	data(data), next(next), child(child) {}
};

void print_list(Node* head) {
	for (Node* node = head; node != nullptr; node = node->next) {
		cout << node->data << " -> ";
		for (Node* childNode = node->child; childNode != nullptr; childNode = childNode->child) {
			cout << childNode->data << " -> ";
		}
		cout << "null" << endl;
		cout << "|" << endl;
	}
	cout << "null";
}

void print_flattenList(Node* head) {
	for (Node* node = head; node != nullptr; node = node->child) {
		cout << node->data << endl;
		cout << "|" << endl;
	}
	cout << "null" << endl;
}

Node* merge2List(Node* left, Node* right) {
	Node* dummy = new Node(-1);
	Node* temp = dummy;

	while (left != nullptr && right != nullptr) {
		if (left->data <= right->data) {
			temp->child = left;
			left = left->child;
		} 
		else {
			temp->child = right;
			right = right->child;
		}

		temp = temp->child;
	}

	if (left != nullptr) temp->child = left;
	else temp->child = right;

	Node* newHead = dummy->child;
	dummy->child = nullptr;
	delete dummy;

	return newHead; 
}

Node* findMiddleNode(Node* head) {
	Node* slow = head;
	Node* fast = head->child;

	while (fast != nullptr && fast->child != nullptr) {
		slow = slow->child;
		fast = fast->child->child;
	}

	return slow;
}

Node* sortList(Node* head) {
	if (head == nullptr || head->child == nullptr) return head;

	Node* mid = findMiddleNode(head);
	Node* left = head;
	Node* right = mid->child;
	mid->child = nullptr;

	left = sortList(left);
	right = sortList(right);

	return merge2List(left, right);
}

Node* flatteningList(Node* head) {
	Node* dummy = new Node(-1);
	Node* temp = dummy;

	Node* node = head;
	while (node != nullptr) {
		Node* next = node->next;
		temp->child = node;
		temp = temp->child;
		temp->next = nullptr;

		Node* childNode = node->child;
		while (childNode != nullptr) {
			temp->child = childNode;
			temp = temp->child;
			childNode = childNode->child;
		}

		node = next;
	}

	head = dummy->child;
	dummy->child = nullptr;
	delete dummy;

	head = sortList(head);

	return head;
}	

int main() {

	Node* head = new Node(5);
    head->child = new Node(11);
    
    head->next = new Node(3);
    head->next->child = new Node(14);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(33);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    // print_list(head);

    head = flatteningList(head);
    print_flattenList(head);


	return 0;
}