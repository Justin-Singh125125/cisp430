#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void enqueue(Node*& front, Node*& rear, int data) {

	if (!front) {
		front = new Node;
		rear = front;
		front->data = data;
		front->next = NULL;
	}
	else {
		//we are going to be adding at the rear everytime for queue
		rear->next = new Node;
		rear = rear->next;
		rear->data = data;
		rear->next = NULL;
	}
}

int dequeue(Node*& front, Node*& rear) {

	if (!front) {
		return NULL;
	}
	int value = 0;
	Node* temp = front;
	if (front == rear) {
		front = rear = NULL;
		value = temp->data;
	}
	else {
		front = front->next;
		value = temp->data;
	}
	delete temp;
	return value;

}

void display(Node* front) {
	while (front) {
		cout << front->data << endl;
		front = front->next;
	}
}

int main()
{
	Node* front = NULL;
	Node* rear = NULL;

	enqueue(front, rear, 1);
	enqueue(front, rear, 2);
	enqueue(front, rear, 3);
	enqueue(front, rear, 4);

	cout << "queue after inserting nodes: " << endl;
	display(front);

	cout << "beggining dequeue process: " << endl;
	cout << dequeue(front, rear) << endl;
	cout << dequeue(front, rear) << endl;

	cout << dequeue(front, rear) << endl;

	cout << dequeue(front, rear) << endl;

	cout << dequeue(front, rear) << endl;
	cout << dequeue(front, rear) << endl;


}

