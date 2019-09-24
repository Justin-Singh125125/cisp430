#include <iostream>

using namespace std;

//create data structure
struct Node {
    int data;
    Node * next;
};


//function defintions
void handleDecimalConversion(Node *& top, const int & decimal);
void handlePush(Node *& top, const int & data);
void handleDisplayStack(Node * top);

//main function
int main() {

    //get a decmial number from user
    int decimal;
    cout << "Enter a decimal number\n";
    cin >> decimal;
    
    //create a node that will point to the top of elements
    Node * top = NULL;
    
    handleDecimalConversion(top,decimal);
    
    cout << "done executing: \n";
    handleDisplayStack(top);
    
    return 0;
}



void handleDecimalConversion(Node *& top, const int &decimal){
    
    //create two necessity variables
    int quotient = decimal;
    int remainder = 0;
    
    do {
        
        //set the quotient and the remainder
        //set remainder first to ensure results
        remainder = (quotient % 2);
        quotient /= 2;
      
        //push remainder onto stack
        handlePush(top, remainder);
        
    } while (quotient!=0);
    
  
}

void handlePush(Node *& top, const int & data){
    
    //if this is the first node to be at top
    if(!top){
        
        //make top point to a new node
        top = new Node;
        top->data = data;
        top->next = NULL;
    }
    
    //if an node already exists in top
    else{
        
        //create a brand new node
        Node * nn = new Node;
        
        //fill node with data
        nn->data = data;
        
        //make the new node connect to whatever top is pointing to
        nn->next = top;
        
        //make top point to the newest top node
        top = nn;
        
    }
}
void handleDisplayStack(Node * top){
    
    //while top doesnt point to null
    
    cout << "top list: " << endl;
    while(top){
        cout << top->data << endl;
        top = top->next;
    }
}
