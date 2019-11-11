#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Stack type
struct Node
{
	int data;
	Node *next;
};

int handlePop(Node *&top)
{
	if (top)
	{

		//make a temp so that we can delete
		Node *temp = top;

		//make top traverse to the next node
		top = top->next;

		//get data from temp
		int data = temp->data;

		//delete temp
		delete temp;

		//return data
		return data;
	}
}

void handlePush(Node *&top, int data)
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
		Node *nn = new Node;

		//fill node with data
		nn->data = data;

		//make the new node connect to whatever top is pointing to
		nn->next = top;

		//make top point to the newest top node
		top = nn;
	}
}

int evaluatedExpression(char *expression)
{
	int result=0;
	//create a stack
	Node *stack = NULL;

	bool isFirst = true;

	//go until the length of the expression
	for (int i = 0; i < strlen(expression); i++)
	{
		//if  any of the expressions characters are an operand, we are going to pop two from the stack
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
		{

			//we are going to pop two pieces off of the stack and convert them to integers


			int b = int(handlePop(stack));
			int a = int (handlePop(stack));

			if (isFirst) {
				b = b - 48;
				a = a - 48;
				isFirst = false;
			}
			else {
				b = b - 48;
			}
	
			//a variable to hold the result
			if (expression[i] == '+')
			{
				result = a + b;
			}
			if (expression[i] == '-')
			{
				result = a - b;
			}
			if (expression[i] == '*')
			{
				result = a * b;
			}
			if (expression[i] == '/')
			{
				result = a / b;
			}



			//push the result back on the stack
			handlePush(stack, result);
		}

		//if any of the characters are not operands, we are going to push onto the stack
		else
		{
			handlePush(stack, expression[i]);
		}
	}
	result = handlePop(stack);
	return result;
}

int main()
{

	//create a variable to read data from text file
	char expression[255];

	//connect to the file
	ifstream read("input.txt");

	//read the line from the text file
	read >> expression;

	cout << "expression read from file: " << expression << endl;

	int result = evaluatedExpression(expression);

	cout << "expression result: " << result << endl;

	return 0;
}