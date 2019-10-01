#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
	string data;
	Node *next;
	Node *prev;
};

void handleDeleteNodes(Node *&head, int numNodesDelete, int maxNodes)
{

	for (int i = 0; i < numNodesDelete; i++)
	{

		Node *temp = head;
		if (maxNodes == 1)
		{
			head = NULL;
		}
		else
		{

			head->next->prev = head->prev;
			head->prev->next = head->next;
			head = head->next;
			maxNodes--;
		}
		delete temp;
	}
}

void handleAppendNode(Node *&head, const string &data)
{

	Node *newNode;
	newNode = new Node;
	newNode->data = data;
	if (!head)
	{
		//nothing in the list, everything points to self
		newNode->prev = newNode;
		newNode->next = newNode;
		head = newNode;
	}
	else
	{

		newNode->prev = head->prev;
		newNode->next = head;
		head->prev = newNode;
		newNode->prev->next = newNode;
		head = newNode;
	}
}
void handleReadFile(Node *&head)
{

	//connect to text file
	ifstream read("input.txt");

	while (read.good())
	{

		string data;
		getline(read, data);

		//add data to list
		handleAppendNode(head, data);
	}

	read.close();
}

int handleNodeAmount(Node *&head)
{

	int count = 0;
	bool isFirst = true;
	Node *tail = head;
	while (tail != head || isFirst)
	{
		head = head->next;
		isFirst = false;
		count++;
	}

	return count;
}

void handleDisplayList(Node *&head)
{
	bool isFirst = true;
	Node *tail = head;
	if (!head)
	{
		cout << "There is nothing in the list!" << endl;
	}
	else
	{
		while (tail != head || isFirst)
		{

			cout << head->data << endl;
			head = head->next;
			isFirst = false;
		}
		cout << endl;
	}
}

int main()
{

	//create a circular link list
	Node *head = NULL;

	handleReadFile(head);

	int maxNodes = handleNodeAmount(head);

	int numNodesDelete = 0;
	cout << "how many nodes would you like to delete? ";
	cin >> numNodesDelete;
	cout << endl;

	if (numNodesDelete > maxNodes)
	{
		cout << "cannot delete more nodes than are available" << endl;
	}
	else
	{
		cout << "List before deletion: " << endl;
		handleDisplayList(head);
		handleDeleteNodes(head, numNodesDelete, maxNodes);
		cout << "List after deletion: " << endl;
		handleDisplayList(head);
	}

	return 0;
}