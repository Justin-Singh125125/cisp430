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
    bool isFirst = true;

    while (current)
    {
        if (current->data < 0)
        {

            Node *temp = current;

            if (isFirst)
            {

                if (current->next)
                {
                    current = current->next;
                    front = prev = current;
                    delete temp;
                }
                else
                {
                    current = prev = front = rear = NULL;
                    delete temp;
                }

                isFirst = false;
            }
            else
            {

                if (front == rear)
                {
                    front = rear = current = prev = NULL;
                    delete temp;
                }
                else
                {
                    if (current == rear)
                    {
                        rear = prev;
                        rear->next = NULL;

                        current = prev = NULL;
                        delete temp;
                    }
                    else
                    {
                        if (front->data < 0)
                        {
                            current = current->next;
                            front = prev = current;
                            delete temp;
                        }
                        else
                        {

                            current = current->next;

                            if (current->data > 0)
                            {
                                prev->next = current;
                                prev = current;
                            }

                            delete temp;
                        }
                    }
                }
            }
        }
        else
        {
            //if there is only one node left
            if (front == rear)
            {
                current = prev = NULL;
            }
            else
            {

                current = current->next;
                if (prev->next != current)
                {
                    prev = prev->next;
                }
                isFirst = false;
            }
        }
    }
}

void displayList(Node *&front)
{
    while (front)
    {
        cout << "number: " << front->data << endl;
        front = front->next;
    }
}
