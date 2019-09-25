#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void handleInitializeQueue(Node *&front, Node *&rear);
void handleEnqueue(Node *&front, Node *&rear, const int &data);
void handleDequeue(Node *&front, Node *&rear, Node *&current, Node *&prev);
void displayList(Node *&front);

int main()
{

    //create a Queue
    Node *front = NULL;
    Node *rear = NULL;

    //initialize the queue with data from a text file
    handleInitializeQueue(front, rear);

    //create a current and previous node that we will use to dequeue
    Node *current = front;
    Node *prev = front;
    handleDequeue(front, rear, current, prev);

    displayList(front);
    return 0;
}

void handleInitializeQueue(Node *&front, Node *&rear)
{

    //connect to text file
    fstream read("numbers.txt");

    //while we do not encounter the end of the file
    while (read.good())
    {

        //create a varaible to hold data from file
        int data;

        //read current line of file
        read >> data;

        //enqueue the current number that was read from the file
        handleEnqueue(front, rear, data);
    }
}
void handleEnqueue(Node *&front, Node *&rear, const int &data)
{

    //create a new node
    Node *nn = new Node;

    //initalize new node
    nn->data = data;
    nn->next = NULL;

    //check if this is the first node that we are enqueueing
    if (!front)
    {

        //make the front and the read point at the new node
        front = rear = nn;
    }

    //if there is already a first node
    else
    {

        //connect to the newest node
        rear->next = nn;

        //make rear point to the new node
        rear = nn;
    }
}
void handleDequeue(Node *&front, Node *&rear, Node *&current, Node *&prev)
{
}

void displayList(Node *&front)
{
    while (front)
    {
        cout << "number: " << front->data << endl;
        front = front->next;
    }
}
