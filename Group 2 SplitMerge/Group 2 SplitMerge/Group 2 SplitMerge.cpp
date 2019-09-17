#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
	string name;
	Node* next;
};

Node* ReadFile();
Node* Merge(Node* list_1, Node* list_2);
void Traverse(Node* head);
void SplitAndMerge(Node* head);




int main()
{
	cout << "Calling ReadFile Function..." << endl;

	//create a list from reading the file
	Node* head = ReadFile();

	cout << "Completed ReadFile Function..." << endl << endl;

	cout << "Calling SplitAndMerge Function..." << endl << endl;
	SplitAndMerge(head);

	cout << "\nFinished SplitAndMerge Function..." << endl;

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

Node* Merge(Node* list_1, Node* list_2) {
	//create a head node
	Node* head = new Node;
	
	//current node to point at head and traverse through
	Node* current = head;

	//create a flag variable
	bool isFirst = true;

	//append list 1 to head
	while (list_1) {

		if (isFirst) {
			//set the first ever node
			head->name = list_1->name;
			head->next = NULL;
			
			//set the flag variable so we do not enter here again
			isFirst = false;

			//traverse to the next node just in case
		
			//traverse to the next node of list_1
			list_1 = list_1->next;
			

		}
		else {

			//create a new Node
			Node* newNode = new Node;
			newNode->name = list_1->name;
			newNode->next = NULL;

			//link the new node to head current
			current->next = newNode;

			//traverse to the next node of list_1
			list_1 = list_1->next;

			//traverse up the head to add new nodes
			current = current->next;
		}
	}

	//append list _2
	while (list_2) {

			//create a new Node
			Node* newNode = new Node;
			newNode->name = list_2->name;
			newNode->next = NULL;

			//link the new node to head current
			current->next = newNode;

			//traverse to the next node of list_1
			list_2 = list_2->next;

			//traverse up the head to add new nodes
			current = current->next;
	}
	
	//return the combined list
	return head;
}




void Traverse(Node* head) {


	while (head) {

		//print out current name
		cout << head->name << endl;

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
	bool isFirst = true;

	//keep track of current node
	Node* currentNode = head;
	Node* currentNewNode = list_1;

	//create first list
	for (int i = 1; i <= (totalNodes / 2); i++) {

		if (isFirst) {
			//get first name
			list_1->name = currentNode->name;

			//set node to null
			list_1->next = NULL;

			//make current head traverse
			currentNode = currentNode->next;

			//set flag variable to false
			isFirst = false;

		}
		else {

			//before we create a new node, lets check to see 
			//if there is even another node to append first
			if (totalNodes != 2) {
				Node* newNode = new Node;


				//set new node to whatever current node is pointing to
				newNode->name = currentNode->name;
				//set newNode next to null
				newNode->next = NULL;

				//link newNode
				currentNewNode->next = newNode;

				//move the currentNewNode to the appended new node
				currentNewNode = currentNewNode->next;

				//if currentNode->next does not have null
				if (currentNode->next) {
					currentNode = currentNode->next;
				}
			}

		}
	}

	//generate second list
	isFirst = true;
	currentNewNode = list_2;

	for (int i = (totalNodes / 2) + 1; i <= totalNodes; i++) {
		if (isFirst) {
			//get first name
			list_2->name = currentNode->name;

			//set node to null
			list_2->next = NULL;

			//make current head traverse
			currentNode = currentNode->next;

			//set flag variable to false
			isFirst = false;

		}
		else {

			if (totalNodes != 2) {
				Node* newNode = new Node;


				//set new node to whatever current node is pointing to
				newNode->name = currentNode->name;
				//set newNode next to null
				newNode->next = NULL;

				//link newNode
				currentNewNode->next = newNode;

				//move the currentNewNode to the appended new node
				currentNewNode = currentNewNode->next;

				//if currentNode->next does not have null
				if (currentNode->next) {
					currentNode = currentNode->next;
				}
			}
		}
	}

	cout << "Calling Traverse function for list 1" << endl;
	Traverse(list_1);

	cout << "\nCalling Traverse function for list 2" << endl;
	Traverse(list_2);

	cout << "\nCalling Merge function..." << endl;
	Node * newList = Merge(list_1, list_2);

	cout << "Finished Merge function..." << endl << endl;


	cout << "Calling Traverse Function for mergedList" << endl;
	Traverse(newList);
}





