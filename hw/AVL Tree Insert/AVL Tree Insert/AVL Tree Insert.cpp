#include <iostream>
#include <fstream>

using namespace std;

struct BinaryTree {
	int height;
	int key;
	BinaryTree* left;
	BinaryTree* right;
};

ofstream write("output.txt");

int max(int a, int b) {

	//if a is more than b, return a, else return b
	return(a > b) ? a : b;
}

int height(BinaryTree* node) {

	//if the node is empty
	if (!node) {
		return 0;
	}

	//if node is not empty, return the current height of it
	return node->height;
}

int getBalance(BinaryTree* N)
{
	{
		if (N == NULL)
			return 0;
		return height(N->left) - height(N->right);
	}
}

BinaryTree* leftRotate(BinaryTree * x)
{
	BinaryTree* y = x->right;
	BinaryTree* T2 = y->left;

	// Perform rotation  
	y->left = x;
	x->right = T2;

	// Update heights  
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root  
	return y;
}

BinaryTree* rightRotate(BinaryTree * y)
{
	BinaryTree* x = y->left;
	BinaryTree* T2 = x->right;

	// Perform rotation  
	x->right = y;
	y->left = T2;

	// Update heights  
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root  
	return x;
}

BinaryTree* rebalance(BinaryTree * node, int key) {

	//asign the current node height
	node->height = max(height(node->left), height(node->right)) + 1;

	//get the balance of the current node
	int balance = getBalance(node);

	// Left Left Case  
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case  
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case  
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case  
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

BinaryTree* treeInsert(BinaryTree * leaf, int data) {

	if (!leaf) {

		// Insertion place found.
		leaf = new BinaryTree;
		leaf->right = NULL;
		leaf->left = NULL;
		leaf->key = data;
		leaf->height = 0;
	}
	else if (data < leaf->key)
	{
		leaf->left = treeInsert(leaf->left, data);
	}

	else if (data > leaf->key) {
		leaf->right = treeInsert(leaf->right, data);
	}

	//rebalance the tree
	leaf = rebalance(leaf, data);
	return leaf;
}

void printGivenLevel(BinaryTree * root, int level)
{

	if (root == NULL)
		return;
	if (level == 1) {
		printf("%d ", root->key);
		write << root->key;
	}


	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

void printLevelOrder(BinaryTree * root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
	{
		printGivenLevel(root, i);
		printf("\n");
	}
}

int main()
{

	//create a empty tree
	BinaryTree* root = NULL;

	//connect to file
	ifstream read("input.txt");

	//while we are not at the end of the file
	while (read.good()) {

		//temp variable to hold current value from file
		int value;

		//read current value from file
		read >> value;

		//insert the value into the tree
		root = treeInsert(root, value);
	}

	read.close();

	printLevelOrder(root);

	write.close();
	return 0;

}

