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

	//creating a stack structure to handle conversion
	Node* top = NULL;

	//create a current to keep track of where we are at on the stack
	Node* current = NULL;



	//create a string for the converted expression
	string convertedExpression = "";


	for (int i = 0; i < expression.length(); i++) {

		//if the current character is one of the operators
		if (expression[i] == '(' || expression[i] == ')' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
		
			//if there is nothing on stack, just push the first operator
			if (!top) {
				top = new Node;
				top->data = expression[i];
				top->next = NULL;

				//make current point to the first top node
				current = top;
			}
			else {
				//make current point to top everytime
				current = top;

				//now we need to do a series of checks
				//check whatever top is pointing to
				Node* nn = new Node;
				nn->data = expression[i];
				nn->next = NULL;
			
				while (current) {

					//
					if ((current->data == "+" && nn->data == "+") || (current->data == "+" && nn->data == "-") || (current->data == "-" && nn->data == "-") || (current->data == "-" && nn->data == "+")) {
						
						//make a temp point to current
						Node* temp = current;

						//make current and top point to the new nn
						top = current = nn;

						//when this happens, we have to pop and add to the current expression
						convertedExpression += temp->data;

						delete temp;

					}

					current = current->next;
				}


			}
		}
		//if the current character is not an operator, just append it to the list
		else {
			convertedExpression += expression[i];
		}
	}

	//since we hit the end of the expression, we now have to pop everything from stack if there is any

	while (top) {
		convertedExpression += top->data;
		top = top->next;
	}




	return convertedExpression;
}
