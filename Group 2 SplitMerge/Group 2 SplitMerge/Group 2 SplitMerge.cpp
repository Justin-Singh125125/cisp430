#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
	string name;
	Node* next;
};

Node* ReadFile();
void Traverse(Node* head);
void SplitAndMerge(Node* head);



int main()
{
	//create a list from reading the file
	Node* head = ReadFile();

	SplitAndMerge(head);

	//Traverse(head);
	return 0;
}

Node* ReadFile() {

	//open text file for reading
	ifstream read("names.txt");

	//create our head node
	Node* head = new Node;

	Node* currentNode = head;

	//a conditional for first node condition
	bool isFirst = true;

	while (read.good()) {

		//if the first node
		if (isFirst) {
			read >> head->name;
			head->next = NULL;
			isFirst = false;
		}

		//create a new node for each name
		Node* newNode = new Node;

		//read current name
		read >> newNode->name;
		newNode->next = NULL;

		//link new node to the head
		currentNode->next = newNode;

		//move current node to the next linked node
		currentNode = currentNode->next;
	}

	//close the file
	read.close();

	return head;
}

void Traverse(Node* head) {


	while (head) {

		//print out current name
		cout << "name: " << head->name << endl;

		//move to the next node
		head = head->next;
	}
}

void SplitAndMerge(Node* head) {

	//keep track of total amount of nodes
	int totalNodes = 0;

	//dummy node
	Node* temp = head;

	while (temp) {
		totalNodes++;
		temp = temp->next;
	}

	//create two lists
	Node* list_1 = new Node;
	Node* list_2 = new Node;

	//flag variables
	bool isFirst_1 = true;
	bool isFirst_2 = true;

	//keep track of current node
	Node* currentNode = head;
	Node* currentNewNode_1 = list_1;
	Node* currentNewNode_2 = list_2;

	for (int i = 1; i < (totalNodes-1); i++) {
		

		//for first list
		if (i < (totalNodes / 2)) {
			
			//precondition for first node
			if (isFirst_1) {
				list_1->name = currentNode->name;
				list_1->next = NULL;
				currentNode = currentNode->next;
				isFirst_1 = false;
			}

			//create a new node
			Node* newNode = new Node;
			newNode->name = currentNode->name;
			newNode->next = NULL;
			currentNewNode_1->next = newNode;
			currentNewNode_1 = currentNewNode_1->next;
			currentNode = currentNode->next;

		}
		
		else {
			//precondition for second node
			if (isFirst_2) {
				list_2->name = currentNode->name;
				list_2->next = NULL;
				currentNode = currentNode->next;
				isFirst_2 = false;
			}

			//create a new node
			Node* newNode = new Node;
			newNode->name = currentNode->name;
			newNode->next = NULL;
			currentNewNode_2->next = newNode;
			currentNewNode_2 = currentNewNode_2->next;
			currentNode = currentNode->next;
		}
		
	
	}




	
	cout << "list 1: " << endl;
	Traverse(list_1);

	cout << "list 2: " << endl;

	Traverse(list_2);


}



