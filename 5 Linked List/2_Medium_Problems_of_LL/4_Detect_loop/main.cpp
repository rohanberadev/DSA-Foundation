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

bool detectLoop_brute(Node* head) {
	Node* node = head;
	unordered_map<Node*, bool> nodeMap;

	while (node != nullptr) {
		if (nodeMap[node]) {
			return true;
		}

		nodeMap[node] = true;
		node = node->next;
	}

	return false;
}

bool detectLoop_optimal(Node* head) {
	Node* slow = head;
	Node* fast = head;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			return true;
		}
	}

	return false;
}

int main() {

	Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // Create a loop
    fifth->next = third; 


    // bool isLoop = detectLoop_brute(head);
    bool isLoop = detectLoop_optimal(head);

    if (isLoop) cout << "Loop is detected in the linked list." << endl;
    else cout << "No loop is detected in the linked list." << endl;

	return 0;
}