#include <iostream>

#include <fstream>

#include <string>

using namespace std;

ifstream in("input.txt");

struct node

{

	node *next;

	string name;
};

struct BinaryTree

{

	string name;

	node *names;

	BinaryTree *left;

	BinaryTree *right;
};

void display(int count, string key)

{

	cout << endl
		 << "There are " << count << " iterations of " << key << endl;
}

void countName(BinaryTree *leaf, string key)

{

	int count = 1; //starts at 1 because there is one from the tree

	node *curr = leaf->names;

	if (!curr)

		display(count, key);

	else

	{

		while (curr)

		{

			count++;

			curr = curr->next;
		}

		display(count, key);
	}

	delete curr;
}

void find(BinaryTree *leaf)

{

	string key;

	cout << "Enter a name you want to search for: " << endl;

	cin >> key;

	bool found = false;

	while (leaf && !found) //finding the leaf that matches our search value

	{

		cout << leaf->name << " ";

		if (key == leaf->name)

		{

			countName(leaf, key); //counts how many times a name is duplicated

			found = true;
		}

		else if (key > leaf->name)

			leaf = leaf->left;

		else

			leaf = leaf->right;
	}
}

void addLink(BinaryTree *&leaf, string name)

{

	node *newNode = new node;

	newNode->name = name;

	if (!leaf->names) //leaf->names = head

		newNode->next = NULL;

	else

		newNode->next = leaf->names;

	leaf->names = newNode;
}

void Insert(BinaryTree *&leaf, string name, bool first)

{

	if (!leaf || first)

	{

		leaf = new BinaryTree;

		leaf->right = NULL;

		leaf->left = NULL;

		leaf->name = name;

		leaf->names = NULL;
	}

	else if (name > leaf->name)

		Insert(leaf->left, name, first); //finding the right place for the name

	else if (name < leaf->name)

		Insert(leaf->right, name, first);

	else if (name == leaf->name)

		addLink(leaf, name); //adding the name to a linked list if it already exists
}

void readFile(BinaryTree *&leaf, bool first)

{

	string names;

	getline(in, names);

	Insert(leaf, names, first); //inserting first name

	first = false;

	while (in.good())

	{

		getline(in, names);

		Insert(leaf, names, first); //Inserts each name into tree
	}

	in.close();
}

int main()

{

	BinaryTree *root = new BinaryTree;

	bool first = true;

	readFile(root, first);

	find(root);

	delete root;

	return 0;
}