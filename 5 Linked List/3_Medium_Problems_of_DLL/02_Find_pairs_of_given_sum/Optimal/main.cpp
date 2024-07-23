#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;

	// constructor
	Node(int data, Node* next = nullptr, Node* prev = nullptr) : 
	data(data), next(next), prev(prev) {}
};

bool empty(Node* head) {
	return head == nullptr;
}

Node* convertArrayToDoublyList(int arr[], int n) {
	Node* head = new Node(arr[0]);
	Node* temp = head;

	for(int i = 1; i < n; i++) {
		Node* node = new Node(arr[i]);
		temp->next = node;
		node->prev = temp;
		temp = temp->next;
	}

	return head;
}

void printDoublyList(Node* head) {
	for (Node* node = head; node != nullptr; node = node->next) {
		cout << node->data << " ";
	}
	cout << endl;
}

Node* findTail(Node* head) {
	Node* tail = head;
	while (tail->next != nullptr) tail = tail->next;

	return tail;
}

vector<pair<int, int>> findPairsOfGivenSum(Node* head, int target) {
	vector<pair<int, int>> ans; 

	Node* left = head;
 	Node* right = findTail(head);

 	while (left->data < right->data) {
        int sum = left->data + right->data;

        if (sum < target) left = left->next;
        else if (sum > target) right = right->prev;
        else {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
    }

 	return ans;
}

int main() {

	int size;
	cin >> size;

	int sum;
	cin >> sum;

	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	Node* head = convertArrayToDoublyList(arr, size);
	printDoublyList(head);

	vector<pair<int, int>> ans = findPairsOfGivenSum(head, sum);

	for (auto it : ans) {
		cout << it.first << " " << it.second << endl;
	}

	return 0;
}