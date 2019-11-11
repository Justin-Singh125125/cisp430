#include <iostream>

using namespace std;

//create data structure
struct Node
{
    int data;
    Node *next;
};

//function defintions
void handleBinaryConversion(Node *&top, const int &decimal);
void handleHexadecimalConversion(Node *&top, const int &decimal);
void handlePush(Node *&top, const int &data);
void handlePopAll(Node *&top);

//main function
int main()
{

    //get a decmial number from user
    int decimal;
    cout << "Enter a decimal number\n";
    cin >> decimal;

    //create a node that will point to the top of elements
    Node *top = NULL;

    //call conversion functions
    handleBinaryConversion(top, decimal);
    handleHexadecimalConversion(top, decimal);

    return 0;
}

void handleBinaryConversion(Node *&top, const int &decimal)
{

    //create two necessity variables
    int quotient = decimal;
    int remainder = 0;

    do
    {

        //set the quotient and the remainder
        //set remainder first to ensure results
        remainder = (quotient % 2);
        quotient /= 2;

        //push remainder onto stack
        handlePush(top, remainder);

    } while (quotient != 0);

    cout << decimal << " converted to binary: ";
    handlePopAll(top);
}

void handleHexadecimalConversion(Node *&top, const int &decimal)
{

    //create two necessity variables
    int quotient = decimal;
    int remainder = 0;

    do
    {

        //set the quotient and the remainder
        //set remainder first to ensure results
        remainder = (quotient % 16);
        quotient /= 16;

        //push remainder onto stack

        handlePush(top, remainder);

    } while (quotient != 0);

    cout << decimal << " converted to hexadecimal: 0x";
    handlePopAll(top);
}

void handlePush(Node *&top, const int &data)
{

    //if this is the first node to be at top
    if (!top)
    {

        //make top point to a new node
        top = new Node;
        top->data = data;
        top->next = NULL;
    }

    //if an node already exists in top
    else
    {

        //create a brand new node
        Node *nn = new Node;

        //fill node with data
        nn->data = data;

        //make the new node connect to whatever top is pointing to
        nn->next = top;

        //make top point to the newest top node
        top = nn;
    }
}

void handlePopAll(Node *&top)
{

    //while top doesnt point to null
    while (top)
    {

        //create a temp node for us to delete
        //and point it at top
        Node *temp = top;

        //make top traverse to the next node;
        top = top->next;

        //display current temp

        if (temp->data > 9)
        {
            char test = temp->data + 55;
            cout << test;
        }
        else
        {
            cout << temp->data;
        }

        //clean up the stack
        delete temp;
    }
    cout << endl;
}
