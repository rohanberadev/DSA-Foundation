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
	Node* node = head;
	Node* prevLast = nullptr;
	for(int i = 1; i < n; i++) {
		node->next = new Node(arr[i]);
		node->prev = prevLast;
		prevLast = node;
		node = node->next;
	}

	return head;
}

void printDoublyList(Node* head) {
	for (Node* node = head; node != nullptr; node = node->next) {
		cout << node->data << " ";
	}
	cout << endl;
}

vector<vector<int>> findPairsOfGivenSum(Node* head, int sum) {
	vector<vector<int>> ans;

	for (Node* I = head; I != nullptr; I = I->next) {
		for (Node* J = I->next; J != nullptr; J = J->next) {
			if (I->data + J->data == sum) {
				vector<int> res;
				res.push_back(I->data);
				res.push_back(J->data);
				ans.push_back(res);
			}
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

	vector<vector<int>> ans = findPairsOfGivenSum(head, sum);

	for (auto res : ans) {
		for (auto it : res) {
			cout << it << " ";
		}
		cout << endl;
	}

	return 0;

}