#include <iostream>

using namespace std;

struct Node {
	Node* next;
	int data;
};

struct Queue {
	Node *front;
	Node *rear;
};

void enqueue(Queue & q, int data) {

	if (!q.front) {
		q.front = new Node;
		q.rear = q.front;
		q.front->data = data;
		q.front->next = NULL;
	
	}
	else {
		//we are going to be adding at the rear everytime for queue
		q.rear->next = new Node;
		q.rear = q.rear->next;
		q.rear->data = data;
		q.rear->next = NULL;
	}
}

int dequeue(Queue &q) {

	if (!q.front) {
		return NULL;
	}
	int value = 0;
	Node* temp = q.front;
	if (q.front == q.rear) {
		q.front = q.rear = NULL;
		value = temp->data;
	}
	else {
		q.front = q.front->next;
		value = temp->data;
		cout << "value: " << value;
	}
	delete temp;
	return value;

}

int main() {

	//create an array of queues
	Queue q[10];

	//initalize all queues to NULL

	for (int i = 0; i < 10; i++) {
		q[i].front = q[i].rear = NULL;
	}

	enqueue(q[0], 5);

	cout << "test: " << dequeue(q[0])<< endl;



	

	return 0;
}