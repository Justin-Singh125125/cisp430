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
	Node* names;
	BinaryTree* left;
	BinaryTree* right;
};

void treeAdd(BinaryTree*& leaf, string name) {
	//create a tree
	leaf = new BinaryTree;
	leaf->left = leaf->right = NULL;
	leaf->name = name;
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

	BinaryTree* temp = root;



	read.close();
}

int main()
{
	readFile();
	return 0;
}

