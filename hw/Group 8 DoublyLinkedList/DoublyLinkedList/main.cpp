#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//doubly linked list data structure
struct Node
{
	string data;
	Node *next;
	Node *prev;
};

//functions
void handleReadFile(vector<string> &names, vector<string> &deleteNames)
{

	//read from a text file
	ifstream read("input.txt");

	//read entire text file
	while (read.good())
	{
		string data;

		getline(read, data);

		//check if the current line of the text file has delete
		//if it does, push data to deleteNames vector
		if (!data.find("delete"))
		{

			//push data to deleteNames vector while removing the delete word
			deleteNames.push_back(data.erase(0, 7));
		}

		//if the current line does not contain a delete
		else
		{

			//push data to names array
			names.push_back(data);
		}
	}
}

void handleDisplayList(Node *head)
{

	while (head->next)
	{
		cout << "data: " << head->data << endl;

		head = head->next;
	}

	cout << "data: " << head->data << endl;

	cout << "==============\n";
	while (head)
	{
		cout << "data: " << head->data << endl;

		head = head->prev;
	}
}

void handlePopulateList(Node *&head, vector<string> names)
{

	Node *current = NULL;

	for (vector<string>::iterator it = names.begin(); it != names.end(); it++)
	{

		//if head is null
		if (!head)
		{
			head = new Node;
			head->data = *it;
			head->prev = NULL;
			head->next = NULL;

			//set current to the head
			current = head;
		}
		else
		{

			//create a new node to connect
			Node *nn = new Node;
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

void handleListDeletion(Node *&head, vector<string> deleteNames)
{

	for (vector<string>::iterator it = deleteNames.begin(); it != deleteNames.end(); it++)
	{

		Node *current = head;

		while (current)
		{

			//check if any of the nodes are to delete
			if (current->data == *it)
			{

				//create a temp that is going to point to the node we want to delete
				Node *temp = current;
				//a check for if its the first node
				if (!head->next)
				{

					//set head and current to null
					head = current = NULL;
				}
				else
				{
					current->prev->next = current->next;
					if (current->next)
					{
						current->next->prev = current->prev;
					}
					current = NULL;
				}

				delete temp;
			}
			else
			{
				current = current->next;
			}
		}
	}
}

int main()
{

	//declare a vector for the names
	vector<string> names;

	//declare a vector for the names we are going to delete
	vector<string> deleteNames;

	//pass in vectors to fill them with data from text file
	handleReadFile(names, deleteNames);

	//sort the names in abc order
	sort(names.begin(), names.end(), less<>());

	//create the data structure
	Node *head = NULL;

	//populate the linked list
	handlePopulateList(head, names);

	//delete the names from the list
	handleListDeletion(head, deleteNames);

	//display the list
	handleDisplayList(head);

	return 0;
}