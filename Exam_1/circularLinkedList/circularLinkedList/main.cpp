#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

void add(Node*& head, int data) {

	if (!head) {
		head = new Node;
		head->next = head->prev = head;
		head->data = data;
	}
	else {
		Node* curr = new Node;
		curr->prev = head;
		curr->next = head->next;
		curr->next->prev = curr;
		head->next = curr;
		curr->data = data;
		head = curr;
	}
}

void display(Node * head){

	Node* curr = head;

	cout << head->data << endl;
	head = head->prev;
	while (curr != head) {
		cout << head->data << endl;
		head = head->prev;
		
	}
}

void deleteNode(Node*& head, int deleteNum) {

	if (head) {

		while (head->data != deleteNum) {
			head = head->next;
		}

		Node* temp = head;

		head->prev->next = head->next;
		head->next->prev = head->prev;

		head = head->next;
			
		delete temp;
	}
}


int main()
{
	Node* head = NULL;

	add(head, 1);
	add(head, 2);
	add(head, 3);
	add(head, 4);

	display(head);

	cout << "delete: " << endl;
	deleteNode(head, 2);
	display(head);

	cout << "delete: " << endl;
	deleteNode(head, 1);
	display(head);
}
