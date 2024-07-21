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

int getLengthOfLoop_brute(Node* head) {
	int count = 0;
	Node* node = head;
	unordered_map<Node*, int> nodeMap;

	while (node != nullptr) {
		if (nodeMap[node] > 0) {
			return count - nodeMap[node]+1;
		}

		count++;
		nodeMap[node] = count;
		node = node->next;
	}

	return 0;
}

int getLengthOfLoop_optimal(Node* head) {
	Node* slow = head;
	Node* fast = head;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			slow = head;

			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}

			slow = slow->next;
			int count = 1;

			while (slow != fast) {
				slow = slow->next;
				count++;
			}

			return count;
		}
	}

	return 0;
}

int main() {

	Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

	cout << getLengthOfLoop_brute(head) << endl;
	cout << getLengthOfLoop_optimal(head);

	return 0;
}