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

	//create a string for the converted expression
	string convertedExpression = "";


	for (int i = 0; i < expression.length(); i++) {

		//if the current character is one of the operators
		if (expression[i] == '(' || expression[i] == ')' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
			cout << expression[i] << endl;

			//begin
		}
		//if the current character is not an operator, just append it to the list
		else {
			convertedExpression += expression[i];
		}
	}


	return convertedExpression;
}
