#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//linked list
struct Node {
	string name;
	Node* next;
};

struct BinaryTree {
	string name;
	Node* head;
	BinaryTree* left;
	BinaryTree* right;
};


int getNumListDuplicates(Node* head) {
	int count = 0;
	while (head) {
		count++;
		head = head->next;
	}

	return count;
}

void listAdd(Node*& head, string name) {


	
	if (!head) {
		head = new Node;
		head->name = name;
		head->next = NULL;

	}

	else {
		Node* curr = head;
		while (curr->next) {
			curr = curr->next;
		}

		curr->next = new Node;
		curr->next->name = name;
		curr->next->next = NULL;

	}
}


BinaryTree* treeSearch(BinaryTree* root, string key, bool state)
{
	// Base Cases: root is null or key is present at root 
	if (root == NULL || root->name == key) {
		state ? cout << root->name << endl : cout << "";
		return root;
	}


	// Key is greater than root's key 
	if (root->name < key) {
		state ? cout << root->name << endl : cout << "";
		return treeSearch(root->left, key, true);

	}

	// Key is smaller than root's key 
	state ? cout << root->name << endl : cout << "";
	return treeSearch(root->right, key, true);
}

void treeAdd(BinaryTree*& leaf, string name) {

	BinaryTree* temp = treeSearch(leaf, name, false);

	if (temp) {
		cout << "adding.. \n";
		listAdd(temp->head, name);
	}
	else {
		//create a tree
		leaf = new BinaryTree;
		leaf->left = leaf->right = NULL;
		leaf->head = NULL;
		leaf->name = name;
	}
}



void treeInsert(BinaryTree*& leaf, string name) {

	//check if there is nothing in the tree
	if (!leaf) {

		//if there is no tree yet, create a leaf and add it
		treeAdd(leaf, name);

	}
	//if the current name is less than what is stored on current leaf
	//append that name onto the right side 
	else if (name < leaf->name) {
		treeInsert(leaf->right, name);
	}
	//if the current name is more than what is stored on current leaf
	//append that name onto the left side 
	else if (name > leaf->name) {
		treeInsert(leaf->left, name);
	}

}

void readFile() {
	ifstream read("input.txt");

	string name;

	//create the root of out tree
	BinaryTree* root = NULL;


	while (read.good()) {
		read >> name;

		//populate the tree
		treeInsert(root, name);


	}



	cout << "NAMES INSERTED...\n\n";

	string searchName = "";
	cout << "ENTER A NAME TO SEARCH FOR ";
	cin >> searchName;

	BinaryTree* temp = treeSearch(root, searchName, true);

	if (temp) {
		cout << "found: ";
		cout << temp->name << endl;

		cout << "THERE ARE " << getNumListDuplicates(temp->head) << " DUPLICATES \n";

	}
	else {
		cout << "SORRY THAT NAME IS NOT IN THE TREE \n";
	}



	read.close();
}

int main()
{
	readFile();
	return 0;
}

