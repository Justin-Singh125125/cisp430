#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void push(Node*& top, int data) {
	if (!top) {
		top = new Node;
		top->data = data;
		top->next = NULL;
	}
	else {
		Node* temp = new Node;
		temp->data = data;
		temp->next = top;
		top = temp;
	}
}

void pop(Node*& top) {

	if (top) {
		Node* temp = top;
		top = top->next;
		cout << temp->data << endl;
		delete temp;
	}
	else {
		cout << "stack is empty" << endl;
	}
}

void display(Node* top) {
	while (top) {
		cout << top->data << endl;
		top = top->next;
	}
}



int main() {

	Node* top = NULL;

	push(top, 1);
	push(top, 2);
	push(top, 3);
	push(top, 4);

	cout << "stack after insertion: " << endl;

	display(top);

	cout << "popping stack: " << endl;
	pop(top);
	pop(top);
	pop(top);

	pop(top);

	pop(top);

	return 0;
}