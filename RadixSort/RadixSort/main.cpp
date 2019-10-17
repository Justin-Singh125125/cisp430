#include <iostream>

using namespace std;

struct Node {
	Node* next;
	int data;
};

struct Queue {
	Node* front;
	Node* rear;
};

const int SIZE = 10;


int getMax(int arr[])
{
	int mx = arr[0];
	for (int i = 1; i < SIZE; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}


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

int dequeue(Queue & q) {

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


void radixSort(Queue* q, int arr[]) {

	//find the maximum number to know the number of digits we going to go by
	int m = getMax(arr);

	//number of passes
	for (int n = 1; n <= m; n *= 10) {

		//number of items in array
		for (int i = 0; i < SIZE; i++) {

			int queueIndex = arr[i] % (10 * n);
			queueIndex /= n;

			enqueue(q[queueIndex], arr[i]);
		}


	}
}

int main() {

	//create an array of queues
	Queue q[SIZE];

	//an array of values to sort
	int arr[SIZE] = { 170, 45, 75, 90, 802, 2, 24, 66, 11, 9 };

	//initalize all queues to NULL
	for (int i = 0; i < 10; i++) {
		q[i].front = q[i].rear = NULL;
	}

	radixSort(q, arr);





	return 0;
}