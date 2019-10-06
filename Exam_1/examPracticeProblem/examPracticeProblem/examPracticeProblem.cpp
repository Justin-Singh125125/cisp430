// examPracticeProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

void add(Node*& head, Node *& tail, int data) {
	if (!head) {
		head = new Node;
		head->prev = NULL;
		head->next = NULL;
		head->data = data;
		tail = head;
	}
	else {
		tail->next = new Node;
		tail = tail->next;
		tail->data = data;
		tail->next = NULL;
	}
		
}

void display(Node* head) {
	while (head) {
		cout << head->data << endl;
		head = head->next;
	}
}


void delNode(int nodeNumber, Node*& head, Node*& tail) {

	if (!head || nodeNumber == 0) {
		return;
	}

	if (nodeNumber == 1) {
		Node* temp = head;
		head->next->prev = NULL;
		head = head->next;
		delete temp;
	}
	else if (head == tail) {

	}
}
int main()
{

	Node* head = NULL;
	Node* tail = NULL;
	add(head, tail, 1);
	add(head, tail, 2);
	add(head, tail, 3);
	add(head, tail, 4);

	display(head);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
