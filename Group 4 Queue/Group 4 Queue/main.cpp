#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void handleEnqueue(Node *&front, Node *&rear, const int &data);
void handleDequeue(Node *&front, Node *&rear);

int main() {
    
    ifstream read("numbers.txt");
    
    int data;
    
    read >> data;
    
    cout << data << endl;
    read >> data;
    
    cout << data << endl;
    
    read.close();
    return 0;
}


void handleEnqueue(Node *&front, Node *&rear, const int &data){
    
}
void handleDequeue(Node *&front, Node *&rear){
    
}
