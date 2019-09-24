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

//main function
int main() {

    //get a decmial number from user
    int decimal;
    cout << "Enter a decimal number\n";
    cin >> decimal;
    
    //create a node that will point to the top of elements
    Node * top = new Node;
    
    handleDecimalConversion(top,decimal);
    
    cout << "done executing: " << top->data;
    
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
        cout << "quotient: " << quotient<< endl;
        cout << "remainder: " << remainder << endl;
        
        //push remainder onto stack
        handlePush(top, remainder);
        
    } while (quotient!=0);
    
    //first case for adding new node
    if(!top->next){
        cout << "top is not pointing to anything";
    }
}

void handlePush(Node *& top, const int & data){
    top->data= 4;
}
