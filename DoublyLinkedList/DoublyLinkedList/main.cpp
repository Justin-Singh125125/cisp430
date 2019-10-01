#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//doubly linked list data structure
struct Node {
	string data;
	Node* next;
	Node* prev;
};

//functions
void handleReadFile(vector<string>& names, vector<string>& deleteNames) {

	//read from a text file
	ifstream read("input.txt");

	//read entire text file
	while (read.good()) {
		string data;

		getline(read, data);

		//check if the current line of the text file has delete
		//if it does, push data to deleteNames vector
		if (!data.find("delete")) {

			//push data to deleteNames vector
			deleteNames.push_back(data);
		}

		//if the current line does not contain a delete
		else {

			//push data to names array
			names.push_back(data);
		}
	}

}

void handleDisplayVector(vector<string> list) {
	for (vector<string>::iterator it = list.begin(); it != list.end(); it++) {
		cout << *it << endl;
	}
}

void handleDisplayList(Node* head) {

	while (head) {
		cout << "data: " << head->data << endl;

		head = head->next;
	}

}

void handlePopulateList(Node*& head, vector<string> names) {

	Node* current = NULL;

	for (vector<string>::iterator it = names.begin(); it != names.end(); it++) {

		//if head is null
		if (!head) {
			head = new Node;
			head->data = *it;
			head->prev = NULL;
			head->next = NULL;

			//set current to the head
			current = head;
		}
		else {

			//create a new node to connect
			Node* nn = new Node;
			nn->data = *it;
			nn->next = NULL;

			//connect to the new node
			current->next = nn;

			//connect new node back to current
			nn->prev = current;

			//make current point to the new node
			current = nn;

		}

	}

}

void erase(std::vector<string>& v, string str)
{
	std::vector<string>::iterator iter = v.begin();

	while (iter != v.end())
	{
		if (*iter == str)
			iter = v.erase(iter);
		else
			iter++;
	}

}

void handleListDeletion(Node*& head, vector<string> deleteNames) {

	for (vector<string>::iterator it = deleteNames.begin(); it != deleteNames.end(); it++) {

		string deleteName = *it;

		//if there is only one node
		if (!head->next) {
			Node* temp = head;
			head = NULL;
			delete temp;
		}
		else {
			Node* current = head;

			while (current) {

				cout << "delete name: " << deleteName << endl;
				cout << "current data: " << current->data << endl;

				//if a node matches the name we are trying to delete
				if (!deleteName.find(current->data)){

					cout << "test delete: " << current->data << endl<<endl;
					//if there are only two nodes
					if (!current->next->next) {

						Node* temp = current;
						current = current->next;

						//move the head to the second node
						head = current;
						head->prev = NULL;

						delete temp;
					}
					//if there are more than two nodes
					else {
						Node* temp = current;
						current->prev->next = current->next;

						current->next->prev = current->prev;

						current = current->next;
						delete temp;
					}
				}
				else {
					current = current->next;
				}
			}
		}
	}

}

int main() {

	//declare a vector for the names
	vector<string> names;

	//declare a vector for the names we are going to delete
	vector<string> deleteNames;

	//pass in vectors to fill them with data from text file
	handleReadFile(names, deleteNames);

	//sort the names in abc order
	sort(names.begin(), names.end(), less <>());

	//create the data structure
	Node* head = NULL;

	//populate the linked list
	handlePopulateList(head, names);

	//handleDisplayList(head);

	erase(deleteNames, "delete ");

	handleDisplayVector(deleteNames);
	//handleDeleting
	//handleListDeletion(head, deleteNames);

	


	return 0;
}