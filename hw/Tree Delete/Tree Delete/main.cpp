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
}

int main()
{

    //start the program
    readFile();

    return 0;
}
