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

    //special condition if the first node is negative
    bool isFirst = true;

    //if there exists a node
    while (current)
    {

        //if the current node is negative
        if (current->data < 0)
        {

            //create a temp to keep track of which negative node
            //so that we can delete it
            Node *temp = current;

            //if the first node is negative
            if (isFirst)
            {

                //move front to the new front
                front = front->next;
                current = current->next;
                prev = prev->next;

                //now that we isolated negative node
                //delete it
                delete temp;

                //set flag variable to false so we never enter here again
                isFirst = false;
            }
            else
            {

                if (current->next)
                {

                    //move current up one so that we can isolate the negative node
                    current = current->next;

                    //connect the previous node that is before the negative node
                    //to the next current node
                    prev->next = current;

                    //now that we linked to the node that is past the negative node
                    //make prev point to current
                    prev = current;

                    //now that temp isolated, delete it
                    delete temp;
                }

                //this is the condition for the last node
                else
                {
                    //set current to nothing
                    current = NULL;

                    //set prev node to null
                    prev->next = NULL;

                    //make the rear point to the previous node
                    rear = prev;

                    //make prev point to nothing
                    prev = null;

                    //now that we isolate the last node, delete it
                    delete temp;
                }
            }
        }
        else
        {

            //now that we are keeping track of the negative node
            //we can traverse our current node and previous node
            current = current->next;

            //set flag variable so we know we are not on first node
            isFirst = false;
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
