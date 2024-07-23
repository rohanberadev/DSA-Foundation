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

Node* merge2List(Node* head1, Node* head2) {
	Node* dummy = new Node(-1);
	Node* temp = dummy;

	while (head1 != nullptr &&  head2 != nullptr) {
		if (head1->data <= head2->data) {
			temp->child = head1;
			head1 = head1->child;
		}
		else {
			temp->child = head2;
			head2 = head2->child;
		}

		temp->next = nullptr;
		temp = temp->child;
	}

	if (head1 != nullptr) temp->child = head1;
	else temp->child = head2;

	dummy->child->next = nullptr;
	Node* mergedHead = dummy->child;
	dummy->child = nullptr; 
	delete dummy;

	return mergedHead;
}

Node* flatteningList(Node* head) {
	if (head == nullptr || head->next == nullptr) return head;

	Node* mergedHead = flatteningList(head->next);
	head = merge2List(mergedHead, head);

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