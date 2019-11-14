#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct BinaryTree
{
    int key;
    BinaryTree *left;
    BinaryTree *right;
};

void preOrder(BinaryTree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(BinaryTree *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void postOrder(BinaryTree *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}
bool treeSearch(BinaryTree *leaf, int key)
{
    bool found = false;
    if (leaf)
    {
        if (key == leaf->key)
            found = true;
        else if (key < leaf->key) //go to the left if small
            found = treeSearch(leaf->left, key);
        else //go to right if bigger
            found = treeSearch(leaf->right, key);
    }
    return found;
}

BinaryTree *treeDelete(BinaryTree *root, int k)
{
    // Base case
    if (root == NULL)
        return root;

    // Recursive calls for ancestors of
    // node to be deleted
    if (root->key > k)
    {
        root->left = treeDelete(root->left, k);
        return root;
    }
    else if (root->key < k)
    {
        root->right = treeDelete(root->right, k);
        return root;
    }

    // We reach here when root is the node
    // to be deleted.

    // If one of the children is empty
    if (root->left == NULL)
    {
        BinaryTree *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        BinaryTree *temp = root->left;
        delete root;
        return temp;
    }

    // If both children exist
    else
    {

        BinaryTree *succParent = root->right;

        // Find successor
        BinaryTree *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        succParent->left = succ->right;

        // Copy Successor Data to root
        root->key = succ->key;

        // Delete Successor and return root
        delete succ;
        return root;
    }
}

void treeAdd(BinaryTree *&leaf, int key)
{
    leaf = new BinaryTree;
    leaf->key = key;
    leaf->left = NULL;
    leaf->right = NULL;
}

void treeInsert(BinaryTree *&leaf, int key)
{
    if (!leaf)
    { // Insertion place found.
        treeAdd(leaf, key);
    }
    else if (key < leaf->key)
        treeInsert(leaf->left, key); //Insert in left subtree.
    else if (key > leaf->key)
        treeInsert(leaf->right, key); //Insert in right subtree.
}

void readFile()
{

    //connect to file
    ifstream read("input.txt");

    //create a tree root
    BinaryTree *root = NULL;

    //while we are not at the end of file
    while (read.good())
    {

        //holds the current line read from the file
        string currentLine;

        //read the entire line of the file and store it in currentLine
        getline(read, currentLine);

        //if the currentLine read contains a delete token, fire that function
        if (!currentLine.find("delete"))
        {

            //filter our the delete token
            currentLine.erase(0, 6);

            //convert currentLine to an integer
            int value = stoi(currentLine);

            //search the tree to see if the value exists
            bool isFound = treeSearch(root, value);

            //if the value is found, we are going to delete it from the tree
            if (isFound)
            {
                treeDelete(root, value);
            }
            else
            {
                //if the value is not found, just insert
                treeInsert(root, value);
            }
        }

        //if current line does not have the delete token, insert it into the binary tree
        else
        {

            //convert currentLine into an integer
            int value = stoi(currentLine);

            //insert the value into the tree
            treeInsert(root, value);
        }
    }

    cout << "PRE-ORDER LIST IN TREE\n";
    preOrder(root);
    cout << endl;

    cout << "IN-ORDER LIST IN TREE\n";
    inOrder(root);
    cout << endl;

    cout << "POST-ORDER LIST IN TREE\n";
    postOrder(root);
    cout << endl;
}

int main()
{

    //start the program
    readFile();

    return 0;
}
