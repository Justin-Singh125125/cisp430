#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node {
	string data;
	Node* next;
};

string handleReadFile();
string handleExpressionConversion(const string& expression);

void handlePush(Node*& top, const string& data);
string handlePop(Node*& top);

int handlePrecedence(const string& character);


int main()
{
	//create a string that is going to hold the expression
	string expression = handleReadFile();

	//convert the string to postfix
	string convertedExpression = handleExpressionConversion(expression);

	cout << "convertedExpression: " << convertedExpression << endl;
}

string handleReadFile() {

	//connect to outside file
	ifstream read("input.txt");

	//create a string to hold data from text file
	string data;

	//read the first line from the text file
	read >> data;

	//close the file
	read.close();

	//return the first line that is read
	return data;
}

string handleExpressionConversion(const string& expression) {
	string convertedExpression = "";

	//create a stack 
	Node* top = NULL;

	for (int i = 0; i < expression.length(); i++) {

		if (expression[i] == '(' || expression[i] == ')' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
			
			//check if stack is empty
			if (handlePop(top) == "\0") {
				handlePush(top, expression.at(i));
			}
			else {
				
				//track precedence
				int currentTopPrecedence = handlePrecedence(top->data);
				int currentExpressionPrecedence = handlePrecedence(expression[i])
			}
		}
		else {
			convertedExpression += expression[i];
		}
	}

	//pop the rest of the data off the stack
	while (top) {
		convertedExpression += handlePop(top);
	}
	


	return convertedExpression;
}


void handlePush(Node*& top, const string& data)
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
		Node* nn = new Node;

		//fill node with data
		nn->data = data;

		//make the new node connect to whatever top is pointing to
		nn->next = top;

		//make top point to the newest top node
		top = nn;
	}
}

string handlePop(Node*& top) {
	if (top) {

		//make a temp so that we can delete
		Node* temp = top;

		//make top traverse to the next node
		top = top->next;

		//get data from temp
		string data = temp->data;

		//delete temp
		delete temp;

		//return data
		return data;
	}
	else {
		return "\0";
	}

}


int handlePrecedence(const string& character) {
	int precedence = -1;

	if (character == "(" || character == ")") {
		precedence = 0;
	}

	if (character == "+" || character == "-") {
		precedence = 1;
	}
	if (character == "*" || character == "/") {
		precedence = 2;
	}

	return precedence;

}
