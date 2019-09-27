#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node {
	char data;
	Node* next;
};

void handleReadFile(char * expression);
void handleExpressionConversion(char* expression,char* convertedExpression);
char handlePop(Node*& top);
void handlePush(Node*& top, char data);
int handlePrecedence(char character);
/*






int handlePrecedence(Node*& top);

*/


int main()
{
	//character array to hold the first line from the text file
	char expression[255];

	//read the first line of the text file and fill the expression array
	handleReadFile(expression);

	//create a variable to hold the converted expression
	char convertedExpression[255];

	//convert the expression to postfix
	handleExpressionConversion(expression, convertedExpression);



}

void handleReadFile(char * expression) {
	//create connection to text file
	ifstream read("input.txt");

	//read the first line from the text file
	read >> expression;

	//close the connectiont to file
	read.close();
}

void handleExpressionConversion(char* expression, char* convertedExpression) {

	//create a string so we can concatenate easily
	string stringExpression = "";

	//create a stack 
	Node* top = NULL;


	for (int i = 0; i < strlen(expression); i++) {

		if (expression[i] == '(' || expression[i] == ')' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {

			//check if stack is empty
			if (!top) {

				//push the current expression character
				handlePush(top, expression[i]);
			}
			else {

				//track precedence
				int currentTopPrecedence = handlePrecedence(top->data);
				int currentExpressionPrecedence = handlePrecedence(expression[i]);


				//condition if precendence is the same
				if (currentTopPrecedence == currentExpressionPrecedence || currentTopPrecedence > currentExpressionPrecedence) {
					
					bool stop = false;
					while (((currentTopPrecedence == currentExpressionPrecedence) || (currentTopPrecedence > currentExpressionPrecedence)) && !stop) {

						//pop off stack
						char currentPop = handlePop(top);

						
						if (currentPop != '(' || currentPop != ')') {
							stringExpression += currentPop;
						}
						
					
						//set the current top variable to the next variable that is on stack
						if (!top) {
							stop = true;
						}
					}

					//when the while loop ends, we push back the current expression onto the stack
					handlePush(top,expression[i]);
				}
				else
				//if whatever is on the stack has lower precedence than the current expression
				{

					handlePush(top, expression[i]);
				}

			}
		}
		else {
			stringExpression += expression[i];
		}
	}

	//pop the rest of the data off the stack
	while (top) {

		char currentPop = handlePop(top);
		if (currentPop != '(' || currentPop != ')') {
			stringExpression += currentPop;
		}

	}

	cout << "converted expression: " << stringExpression << endl;

	
	

	
}

char handlePop(Node*& top) {
	if (top) {

		//make a temp so that we can delete
		Node* temp = top;

		//make top traverse to the next node
		top = top->next;

		//get data from temp
		char data = temp->data;

		//delete temp
		delete temp;

		//return data
		return data;
	}
	else {
		return '\0';
	}

}

void handlePush(Node*& top, char data)
{
	cout << "data push: " << data << endl;

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

/*
string handleExpressionConversion(const string& expression) {
	string convertedExpression = "";

	//create a stack 
	Node* top = NULL;

	for (int i = 0; i < expression.length(); i++) {

		if (expression[i] == '(' || expression[i] == ')' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
			
			//check if stack is empty
			if (handlePop(top) == "\0") {
				handlePush(top, expression[i]);

			}
			else {
				
				//track precedence
				
			
				cout << "top: " << top->next << endl;
				//cout << "current top data: " << test << endl;
				//int currentTopPrecedence = handlePrecedence();

				//cout << "currentTopPrecedence: " << currentTopPrecedence << endl;
				//int currentExpressionPrecedence = handlePrecedence(&expression[i]);
			}
		}
		else {
			convertedExpression += expression[i];
		}
	}

	//pop the rest of the data off the stack
	//while (top) {
	//	convertedExpression += handlePop(top);
	//}
	


	return convertedExpression;
}






*/


int handlePrecedence(char character) {

	int precedence = -1;

	if (character == '(' || character == ')') {
		precedence = 0;
	}
	if (character == '+' || character == '-') {
		precedence = 1;
	}
	if (character == '*' || character == '/') {
		precedence = 2;
	}
	

	return precedence;

}
