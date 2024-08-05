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

vector<int> convertListToArray(Node* head) {
	vector<int> vec;
	for (Node* node = head; node != nullptr; node = node->next) {
		vec.push_back(node->data);
	}

	return vec;
}

void merge(vector<int> &arr, int low, int mid, int high) {
	vector<int> temp;
	int left = low;
	int right = mid + 1;

	while (low <= mid && right <= high) {
		if (arr[left] <= arr[right]) {
			temp.push_back(arr[left]);
			left++;
		} else {
			temp.push_back(arr[right]);
			right++;
		}
	}

	while (left <= mid) {
		temp.push_back(arr[left]);
		left++;
	}

	while (right <= high) {
		temp.push_back(arr[right]);
		right++;
	}

	for (int i = low; i <= high; i++) {
		arr[i] = temp[i-low];
	}
}

void mergeSort(vector<int> &arr, int low, int high) {
	if (low >= high) return;

	int mid = (low + high) / 2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);

	merge(arr, low, mid, high);
}

Node* mergeSortList(Node* head) {
	vector<int> arr = convertListToArray(head);
	mergeSort(arr, 0, arr.size()-1);

	Node *node = head;
	for (int i = 0; i < arr.size(); i++) {
		node->data = arr[i];
		node = node->next;
	}

	return head;
}

int main() {

	int size; 
	cin >> size;

	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	Node* head = convertArrayToList(arr, size);
	print_list(head);

	head = mergeSortList(head);
	print_list(head);

	return 0;
}