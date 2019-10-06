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

		tail->next->prev = tail;
		tail = tail->next;
		tail->data = data;
		tail->next = NULL;
	}
		
}

void display(Node* tail) {
	while (tail) {
		cout << tail->data << endl;
		tail = tail->prev;;
	}
}


void delNode(int nodeNumber, Node*& head, Node*& tail) {

	if (!head || nodeNumber == 0) {
		return;
	}

	Node* temp = head;
	for (int i = 1; i < nodeNumber; i++) {
		temp = temp->next;
	}

	if (!temp->prev) {
		head->next->prev = NULL;
		head = head->next;
		
	}

	else if (temp == tail) {
		tail = tail->prev;
		temp->prev->next = NULL;
	}
	else if (head == tail) {
		head = tail = NULL;
	}
	else {
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}

	delete temp;
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

	cout << "deleting node: " << endl;
	delNode(3, head, tail);


	display(tail);



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
